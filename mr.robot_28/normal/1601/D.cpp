#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 1e6 + 100;
int Tree[4 * N];
int Tree1[4 * N];
void update1(int v, int l, int r, int idx){
    if(l == r){
        Tree1[v]++;
        return;
    }
    if(idx <= (r + l) / 2){
        update1(v * 2, l, (r + l) / 2, idx);
    }
    else{
        update1(v * 2 + 1, (r + l) / 2 + 1, r, idx);
    }
    Tree1[v]++;
}
int get1(int v, int l, int r, int al, int ar){
    if(al > ar){
        return 0;
    }
    if(l >= al && r <= ar){
        return Tree1[v];
    }
    if(l <= ar && r >= al){
        return get1(v * 2, l, (r + l) / 2, al, ar) + get1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
void update(int v, int l, int r, int idx, int x){
    if(l == r){
        Tree[v] = max(Tree[v], x);
        return;
    }
    if(idx <= (r + l) / 2){
        update(v * 2, l, (r + l) / 2, idx, x);
    }
    else{
        update(v * 2 + 1, (r + l) / 2 + 1, r, idx, x);
    }
    Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
}
int get(int v, int l, int r, int al, int ar){
    if(l >= al && r <= ar){
        return Tree[v];
    }
    if(l <= ar && r >= al){
        return max(get(v * 2, l, (r + l) / 2, al, ar), get(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    return 0;
}

        vector <pair <int, int> > vec;
        vector <int> uniqa;
int n, d;
int genious(){
    fill(Tree1, Tree1 + 4 * (n + 1), 0);
    fill(Tree, Tree + 4 * (n + 1), 0);
    sort(uniqa.begin(), uniqa.end());
    uniqa.resize(unique(uniqa.begin(), uniqa.end()) - uniqa.begin());
    n = sz(uniqa) + 1;
    vector <vector <int> > a_vec(sz(uniqa) + 1);
    for(int i = 0; i < sz(vec); i++){
        int j = upper_bound(uniqa.begin(), uniqa.end(), vec[i].X) - uniqa.begin();
        a_vec[j].push_back(vec[i].Y);
    }    
    vector <vector <int> > adds(n);
   // cout << ans << "\n";
    for(int i = 0; i < n; i++){
        sort(a_vec[i].begin(), a_vec[i].end());
        for(auto a : a_vec[i]){
            int j = lower_bound(uniqa.begin(), uniqa.end(), a) - uniqa.begin();
            adds[j + 1].push_back(i);
        }
    }
    int ans1 = 0;
    for(int i = 0; i < n; i++){
        for(auto v : adds[i]){
            update1(1, 0, n - 1, v);
        }
        int cnt = 0;
        int value;
        if(i == 0){
            value = d;
        }
        else{
            value = uniqa[i - 1];
        }
        //cout << "A " << i << " ";
        for(auto a : a_vec[i]){
            if(a <= value){
                cnt++;
            }
          //  cout << a << " ";
        }
       // cout << "\n";
        cnt += get(1, 0, n - 1, i, i);
        if(i != n - 1){
            update(1, 0, n - 1, i + 1, cnt);
        }
        ans1 = max(ans1, cnt + get1(1, 0, n - 1, i + 1, n - 1));
        for(auto a : a_vec[i]){
            int j = lower_bound(uniqa.begin(), uniqa.end(), a) - uniqa.begin();
            if(a > value){
                int value_add = 0;
                if(j > i){
                    value_add = get1(1, 0, n - 1, i + 1, j);
                }
                update(1, 0, n - 1, j + 1, cnt + 1 + value_add);
            }
        }
    }
    return ans1;
}
int n1;
int stupid(){
    n = sz(vec);
    if(n == 0){
        return 0;
    }
    sort(vec.begin(), vec.end());
    vector <int> dp(1 << n, 0);
    vector <int> maxa(1 << n, 0);    
    int ans = 0;
    for(int i = 0; i < n; i++){
        dp[(1 << i)] = 1;
        ans = 1;
        maxa[1 << i] = vec[i].Y;
    }
    for(int msk = 1; msk < (1 << n); msk++){
        for(int j = 0; j < n; j++){
            if((1 << j) & msk){
                continue;
            }
            maxa[msk | (1 << j)] = max(maxa[msk], vec[j].Y);
            if(vec[j].X >= maxa[msk]){
                dp[msk | (1 << j)] = dp[msk] + 1;
                ans = max(ans, dp[msk | (1 << j)]);
            }
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        cin >> n >> d;
        //n = 20;
       // n1 = n;
        //d = rand() % 10;
        int ans = 0;
        vector <int> s1(n), a1(n);
        for(int i = 0; i < n; i++){
            int s, a;
            cin >> s >> a;
           // s = rand() % 10;
           // a = rand() % 10;
            s1[i] = s;
            a1[i] = a;
            if(s < d){
                continue;
            }
            if(a <= d){
                ans++;
            }
            else{
                vec.push_back({s, a});
                uniqa.push_back(a);
            }  
        }
        cout << ans + genious() << "\n";
       /*int val1 = stupid();
        int val2 = genious();
        vec.clear();
        uniqa.clear();
      //  cout << val1 << "\n";
        if(val1 != val2){
            cout << "A " << n1 << " " << d << "\n";
            for(int i = 0; i < n1; i++){
                cout << s1[i] << " " << a1[i] << "\n";
                if(s1[i] >= d && a1[i] <= d){
                    cout << "TUT\n";
                }
            }
            cout << ans << " ";
            cout << ans + val1 << " " << ans + val2 << "\n";
            return 0;
        }*/
    }
   // cout << "done";
    return 0;
}