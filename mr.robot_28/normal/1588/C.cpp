#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
#define ll long long
const int N = 3e5 + 100;

ll Tree[2][4 * N], Tree_push[2][4 * N]; 
void push(int id, int v){
    Tree[id][v * 2] += Tree_push[id][v];
    Tree_push[id][v * 2] += Tree_push[id][v];
    Tree[id][v * 2 + 1] += Tree_push[id][v];
    Tree_push[id][v * 2 + 1] += Tree_push[id][v];
    Tree_push[id][v] = 0;
}
void update(int id, int v, int l, int r, int al, int ar, int x){
    if(al > ar){
        return ;
    }
    if(l >= al && r <= ar){
        Tree[id][v] += x;
        Tree_push[id][v] += x;
        return;
    }
    if(l <= ar && r >= al){
        push(id, v);
        update(id, v * 2, l, (r + l) / 2, al, ar, x);
        update(id, v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
        Tree[id][v] = min(Tree[id][v * 2], Tree[id][v * 2 + 1]);
    }
}
int go_to(int id, int v, int l, int r){
    if(l == r){
        if(Tree[id][v] < 0){
            return l - 1;
        }
        return l;
    }
    push(id, v);
    if(Tree[id][v * 2] >= 0){
        return go_to(id, v * 2 + 1, (r + l) / 2 + 1, r);
    }
    return go_to(id, v * 2, l, (r + l) / 2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <ll> pref(n + 1);
        vector <int> arr(n);
        map <pair <ll, int>, vector <int> > mp;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            pref[i + 1]  = arr[i] - pref[i];
        }
        arr.push_back(-1);
        pref.push_back(-1  - pref.back());
        n++;
        for(int i = 0; i <= n; i++){
            mp[{pref[i], i % 2}].push_back(i);
        }
        for(auto v : mp){
            sort(v.Y.begin(), v.Y.end());
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j< 4 * n; j++){
                Tree[i][j] = Tree_push[i][j] = 0;
            }
        }
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--){
            int id = i % 2;
            int st = i / 2;
            int en = (n + 1 - id) / 2;
            update(id, 1, 0, en - 1, st, en - 1, arr[i]);
            update(1 - id, 1, 0, (n + id) / 2 - 1, (i + id) / 2, (n + id) / 2 - 1, -arr[i]);
            int i1 = (go_to(0, 1, 0, (n + 1) / 2 - 1) + 1) * 2;
            int i2 = (go_to(1, 1, 0, n / 2 - 1) + 1) * 2 + 1;
            int u = min(i1, i2);
            ll a = pref[i];
            if(mp.count({a, i % 2})){
                int l = -1, r = (int)mp[{a, i % 2}].size();
                while(r - l > 1)
                {
                    int midd = (r + l) / 2;
                    if(mp[{a, i % 2}][midd] > u){
                        r = midd;
                    }
                    else{
                        l = midd;
                    }
                }
                int l1 = -1, r1  = (int)mp[{a, i % 2}].size();
                while(r1 - l1 > 1){
                    int midd = (r1 + l1) / 2;
                    if(mp[{a, i % 2}][midd] <= i){
                        l1 = midd;
                    }
                    else{
                        r1 = midd;
                    }
                }
          //      if(i == 0 && n == 2){
                   // for(auto v : mp[{a, i % 2}]){
                 //       cout << v << " ";
               //     }
             //       cout << u << " " << l1 << " " << l << "\n";
            //    }
                ans += l - l1;
            }
            if(mp.count({-a, 1 - i % 2})){
                int l = -1, r = (int)mp[{-a, 1 - i % 2}].size();
                while(r - l > 1)
                {
                    int midd = (r + l) / 2;
                    if(mp[{-a, 1 - i % 2}][midd] > u){
                        r = midd;
                    }
                    else{
                        l = midd;
                    }
                }
                int l1 = -1, r1  = (int)mp[{-a, 1 - i % 2}].size();
                while(r1 - l1 > 1){
                    int midd = (r1 + l1) / 2;
                    if(mp[{-a, 1 - i % 2}][midd] <= i){
                        l1 = midd;
                    }
                    else{
                        r1 = midd;
                    }
                }
                ans += l - l1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}