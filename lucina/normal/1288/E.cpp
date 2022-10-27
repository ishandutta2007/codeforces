#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
template<class T> using orderset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int const nax = 3e5 + 10;

int n, m, l[nax], r[nax], last[nax];
orderset<pair<int, int>> s;

int main(){
    scanf("%d %d", &n, &m);
    iota(l + 1 , l + 1 + n, 1);
    iota(r + 1 , r + 1 + n , 1);
    for(int i = 1 ; i <= n; i ++){
        s.insert(make_pair(i, i));
        last[i] = i;
    }
    for(int i = 1  ;i <= m ; i ++){
        int x;
        scanf("%d", &x);
        l[x] = 1;
        int pos = (int)s.order_of_key(make_pair(last[x], x)) ;
        ++ pos;
      //  cout << pos << endl;
        r[x] = max(r[x], pos);
        s.erase(make_pair(last[x], x));
        last[x] = -i;
        s.insert(make_pair(last[x], x));
    }
    for(int i = 1 ;i <= n; i++){
        r[i] = max(r[i], ((int)s.order_of_key((make_pair(last[i], i)))) + 1);
    }
    for(int i = 1; i <= n; i ++){
        printf("%d %d\n", l[i], r[i]);
    }
}

///another way