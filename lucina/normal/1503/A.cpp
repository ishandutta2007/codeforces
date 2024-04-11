#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    string a, b;
    #define N return puts("NO"), void();
    int o = count(s.begin(), s.end(), '1'), z = n - o;
    int b1 = 0, b2 = 0, x=0,y=0;
    for (int i = 0 ; i < n ; ++ i){
        if (s[i]=='1'){
            char v = (x*2<o)?'(':')';
            x++;
             a +=v, b+=v;
        }  else{
             char v = y ?'(':')';
             char w = !y?'(':')';
              y ^=1;
              a+=v,b+=w;
        }
        b1+=a.back()=='('?1:-1; b2+=b.back()=='('?1:-1;
        if (b1 < 0 || b2 < 0) N
    }
    if(b1 || b2) N
     puts("YES");
     cout <<a << endl << b<<  endl;
    
}
main() {
    int T;
    for (cin >> T; T--;)solve();
}