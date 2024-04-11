#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
vector <pair <int, int> > Tree[4 * N];    
int n, q, k;

void update1(int id_k, int v, int l, int r, int al, int ar, int k_x, int b_x){
    if(l >= al && r <= ar){
        Tree[id_k][v].X += k_x;
        Tree[id_k][v].Y += b_x;
        return;
    }
    if(l <= ar && r >= al){
        int midd = (r + l) / 2;
        int left = max(0LL, midd - max(al, l) + 1);
        update1(id_k, v * 2, l, midd, al, ar, k_x, b_x);
        update1(id_k, v * 2 + 1, midd + 1, r, al, ar,k_x,  b_x);
    }
}
int get(int id_k, int v, int l, int r, int idx){
    int add_val = Tree[id_k][v].X * idx + Tree[id_k][v].Y;
    if(l == r){
        return add_val;
    }
    int midd = (r + l) / 2;
    if(idx <= midd){
        return add_val + get(id_k, v * 2, l, midd, idx);
    }
    else{
        return add_val + get(id_k, v * 2 + 1, midd + 1, r, idx);
    }
}
void update(int v, int l_k, int r_k, int al_k, int ar_k, int al_x, int ar_x, int k_x, int b_x){
    if(al_k <= l_k && r_k <= ar_k){
        update1(v, 1, 0, n / k, al_x, ar_x, k_x, b_x);
    }
    else if(l_k <= ar_k && r_k >= al_k){
        update(v * 2, l_k, (r_k + l_k) / 2, al_k, ar_k, al_x, ar_x, k_x, b_x);
        update(v * 2 + 1, (r_k + l_k) / 2 + 1, r_k, al_k, ar_k, al_x, ar_x, k_x, b_x);
    }
}
int query(int v, int l_k, int r_k, int idx_k, int idx_x){
    int val = get(v, 1, 0, n / k, idx_x);
    if(l_k == r_k){
        return val;
    }
    int midd_k = (l_k + r_k) / 2;
    if(idx_k <= midd_k){
        return val + query(v * 2, l_k, midd_k, idx_k, idx_x);
    }
    else{
        return val + query(v * 2 + 1, midd_k + 1, r_k, idx_k, idx_x);
    }
}
void build(int v_k, int l_k, int r_k){
    Tree[v_k].resize(4 * (n / k + 1), make_pair(0, 0));
    for(int u = 0; u < 4 * (n / k + 1); u++){
        Tree[v_k][u] = make_pair(0, 0);
    }
    if(l_k == r_k){
        return;
    }
    int midd = (l_k + r_k) / 2;
    build(v_k * 2, l_k, midd);
    build(v_k * 2 + 1, midd + 1, r_k);
}
        
vector <vector <pair <int, int> > > queries;
vector <int> a;
vector <int> ans, lq, rq;
void ingenious(){
    vector <pair <int, int> > st;
    st.push_back({-1, n});
    for(int i = n - 1; i >= 0; i--){
        while(sz(st) > 0 && st.back().X >= a[i]){
            int l = st.back().Y;
            int val = st.back().X;
            val = a[i] - val;
            st.pop_back();
            int r = st.back().Y - 1;
            int t_l = l % k;
            int t_r = r % k;
            int del_l = l / k;
            int del_r = r / k;
            if(k - t_l + l > r){
                update(1, 0, k - 1, t_l, t_r, del_l, n / k, 0, val);
            }
            else{
                int l1 = l + k - t_l;
                int cnt = (r - l1) / k;
                update(1, 0, k - 1, t_l, k - 1, del_l, n / k, 0, val);
                if(l1 + k <= r){
                    update(1, 0, k - 1, 0, k - 1, del_l + 1, del_r - 1, val, -val * (del_l));
                }
                update(1, 0, k - 1, 0, k - 1, del_r, n / k, 0, cnt * val);
                update(1, 0, k - 1, 0, t_r, del_r, n / k, 0, val);
            }
        }
        st.push_back({a[i], i});
        update(1, 0, k - 1, i % k, i % k, i / k, n / k, 0, a[i]);
        for(auto qu : queries[i]){
            int r = qu.X;
            int idx = qu.Y;
        //    cout << i << " " << idx << "\n";
            ans[idx] = query(1, 0, k - 1, i % k, i / k + (r - i) / k);
        }
    }
}
int stupid(int l, int r){
    int sum = 0;
    int mina = 1e9;
    for(int i = l; i <= r; i++){
        mina = min(mina, a[i]);
        if((i - l) % k == 0){
            sum += mina;
        }
    }
    return sum;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> k;
    build(1, 0, k - 1);
    a.resize(n);
    queries.resize(n);
    lq.resize(q);
    rq.resize(q);
    ans.resize(q);
    for(int i = 0; i < n; i++){
       cin >> a[i];
    //    a[i] = rand();
    } 
    for(int i = 0; i < q; i++)
    {
        int l, r;
    //    l = rand() % n + 1;
      //  r = l + rand() % min(n - l + 1, 15LL);
        cin >> l >> r;
        l--;
        r--;
        if(l > r){
            swap(l, r);
        }
        lq[i] = l;
        rq[i] = r;
        queries[l].push_back({r, i});
    }
    ingenious();
 /*   for(int i = 0; i < n; i++){
        queries[i].clear();
        if(stupid(lq[i], rq[i]) != ans[i]){
            cout << ans[i] << "\n";
            cout << stupid(lq[i], rq[i]) << "\n";
            for(int j = lq[i]; j <= rq[i]; j++){
                cout << a[j] << " ";
            }
            return 0;
        }
    }
    }
   */
   for(int i = 0; i < q; i++){
    cout << ans[i] << "\n";
   } 
    return 0;
}