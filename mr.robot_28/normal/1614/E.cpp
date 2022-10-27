#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;
const int K = 1e7;

int Tree_left[K], Tree_right[K], Temp[K];
int Temp_max[K];
int it = 2;
void process(int v, int l, int r){
    if(Tree_left[v] == -1){
        Temp_max[it] = ( r + l)  / 2;
        Tree_left[v] = it++;
    }
    if(Tree_right[v] == -1){
        Temp_max[it] = r;
        Tree_right[v] = it++;
    }
    int add = Temp[v];
    Temp[v] = 0;
    int k1 = Tree_left[v], k2 = Tree_right[v];
    Temp[k1] += add;
    Temp[k2] += add;
    Temp_max[k1] += add;
    Temp_max[k2] += add;
}
void update(int v, int l, int r, int al, int ar, int up){
    if(r < al || l > ar){
        return;
    }
    if(l >= al && r <= ar){
        Temp[v] += up;
        Temp_max[v] += up;
        return;
    }
    process(v, l, r);
    update(Tree_left[v], l, (r + l) / 2, al, ar, up);
    update(Tree_right[v], (r + l) / 2 + 1, r, al, ar, up);
    Temp_max[v] = max(Temp_max[Tree_left[v]], Temp_max[Tree_right[v]]);
}
int get(int v, int l, int r, int x){
    if(v == -1){
        return 0;
    }
    int m = (r + l) / 2;
    if(x <= m){
        return Temp[v] + get(Tree_left[v], l, m, x);
    }
    else{
        return Temp[v] + get(Tree_right[v], m + 1, r, x);
    }
}
int go_to1(int v, int l, int r, int temp){
    if(v == -1){
        return r;
    }
 //   cout << "A " << v << " " << l << " " << r << " " << Temp_max[v] << "\n";
    if(l == r){
    //    cout << l << " " << r << " " << Temp_max[v] << " " ;
        if(temp > Temp_max[v]){
            return l;
        }
        return l - 1;
    }
    process(v, l, r);
    int k1 = Tree_left[v];
    int k2 = Tree_right[v];
    if(Temp_max[k1] < temp){
        return go_to1(k2, (r + l) / 2 + 1, r, temp);
    }
    else{
        return go_to1(k1, l, (r + l) / 2, temp);
    }
}
int go_to2(int v, int l, int r, int temp){
    if(v == -1){
        return r;
    }
    if(l == r){
        if(temp >= Temp_max[v]){
            return l;
        }
        return l - 1;
    }
    process(v, l, r);
    int k1 = Tree_left[v];
    int k2 = Tree_right[v];
    if(Temp_max[k1] <= temp){
        return go_to2(k2, (r + l) / 2 + 1, r, temp);
    }
    else{
        return go_to2(k1, l, (r + l) / 2, temp);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    fill(Tree_left, Tree_left + K, -1);
    fill(Tree_right, Tree_right + K, -1);
    int lastans = 0;
    int M = 1e9;
    Temp_max[1] = 1e9;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        int f1 = go_to1(1, 0, M, t);
        int f2 = go_to2(1, 0, M, t);
      //  cout << f1 << " " << f2 << " ";
        if(f1 >= 0){
            update(1, 0, M, 0, f1, 1);
        }
        if(f2 + 1 <= M){
            update(1, 0, M, f2 + 1, M, -1);
        }
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            x = (x + lastans) % (M + 1);
            lastans = get(1, 0, M, x) + x;
            cout << lastans << "\n";
        }
    }
    return 0;
}