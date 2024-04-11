#include <bits/stdc++.h>
#include <bits/extc++.h> // comment this line if cpp 20, use other two lines instead
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
int calc(char ch){
    if(isupper(ch))return 0;
    else if(islower(ch))return 1;
    else return 2;
}
void eat(){
    // "eatforces"
    string s;
    cin>>s;
    int freq[3]={};
    for(auto i:s)freq[calc(i)]++;
    string fuck="Aa0";
    for(auto&i:s){
        int x=calc(i);
        if(freq[x]>1){
            for(int j=0;j<3;j++){
                if(!freq[j]){
                    freq[x]--;
                    freq[j]++;
                    i=fuck[j];
                    break;
                }
            }
        }
    }
    cout<<s<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}