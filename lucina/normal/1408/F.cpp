#include<bits/stdc++.h>
using namespace std;
/// note: writing on IPAD 
int n;
int m,b;
vector < pair <int,int>> ans;
void out(int a, int b){
    ans.emplace_back(a + 1,b+1);
}
void out(){
       cout << ans.size() << endl;
       for (auto [a, b] : ans) printf("%d %d\n", a, b);
}

main(){
        cin >> n;
        for (int i = 0 ; i < 17; ++ i)
            if (n>>i&1) b = i;
         m = 1 << b;
         for (int i = 0 ; i <= b ; ++ i) {
         for (int j = 0; j + (1 << (i+1))<= m;){
         for ( int v = 0; v < 1 << i ; ++ v)
               out(j + v, j + v + (1 << i));
          j += (1 << (i+1));
 }
}
int bar = n - m-1;
for (int v = 0, x = ans.size(); v < x;++v)
        out(ans[v].first + bar, ans[v].second+bar);
out();

}