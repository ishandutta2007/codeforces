#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int bin_pow(int a, int b, int c) {
    if (b==0) return 1;
    if (b&1) return (ll(a)*bin_pow(a,b-1,c))%c;
    else return sqr(ll(bin_pow(a,b>>1,c)))%c;
}

string b_str, n_str;

vector<int> rem, mod, phi;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int c, cc; 
    getline(cin,b_str,' '); getline(cin,n_str,' '); scanf("%d",&c);
    
    REP(i,sz(b_str)) if (b_str[i]<'0' || b_str[i]>'9') while(1);
    REP(i,sz(n_str)) if (n_str[i]<'0' || n_str[i]>'9') while(1);
    
    cc = c;

    int b = 0;
    REP(i,sz(b_str)) b = (ll(b)*10+(b_str[i]-'0'))%c;//b = b mod c
    
    //cerr << b;

    if (sz(n_str)>9) {
        //return 0;
        //int phi = 1;
        FORD(i,2,32000) if (c%i==0) {
            rem.pb(0); mod.pb(1);
            int &pr = mod.back();
            
            while (c%i==0) {
                c /= i; pr *= i; 
            }
            
            phi.pb(pr/i*(i-1));

            if (b%i==0) {
                rem.back() = 0;
            } else {
                int n = 0;
                REP(i,sz(n_str)) n = (ll(n)*10+(n_str[i]-'0'))%phi.back();
                if (n==0) n = phi.back(); n--;
                rem.back() = bin_pow(b%pr,n,pr);
            }
            
        }
        
        if (c!=1) {
            rem.pb(0); mod.pb(c); phi.pb(c-1);
            int &pr = mod.back();

            if (b%c==0) {
                rem.back() = 0;
            } else {
                int n = 0;
                REP(i,sz(n_str)) n = (ll(n)*10+(n_str[i]-'0'))%phi.back();
                if (n==0) n = phi.back(); n--;
                rem.back() = bin_pow(b%pr,n,pr);
            }
        }

        //REP(i,sz(mod)) cerr << mod[i] << ' ';

        //cerr << n;
        
        vector<int> ans;
        
        REP(i,sz(rem)) {
            ans.pb(rem[i]);
            REP(j,i) {
                ans[i] = ll(bin_pow(mod[j]%mod[i],phi[i]-1,mod[i]))*(ans[i]-ans[j])%mod[i];
                if (ans[i]<0) ans[i] += mod[i];
            }
            if (ans[i]<0) while (1);
        }
        
        int Ans = 0, mult = 1;
        REP(i,sz(rem)) {
            Ans += ll(ans[i])*mult;
            Ans %= cc;
            mult *= mod[i];
        }

        //if (mult != cc) while (1);

        if (b==0) b = cc; b--;

        Ans = (ll(b)*Ans)%cc;
        if (Ans==0) Ans = cc;
        printf("%d",Ans);
        
    } else {
        int n = 0;
        REP(i,sz(n_str)) n = n*10 + n_str[i]-'0';
        int ans = bin_pow(b,n-1,cc);
        if (b==0) b = cc; b--;

        ans = (ll(b)*ans)%cc;
        if (ans==0) ans = cc;
        printf("%d",ans);
        
    }
    
}