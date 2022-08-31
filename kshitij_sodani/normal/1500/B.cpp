//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m,k;
llo nn,mm;
llo aa[5000001];
llo bb[5000001];
llo vis[5000001];
llo gg;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}


llo t;
const llo N=20;
long long cc[N], pp[N], ans, lcm2;
llo solve(llo l,llo r){
		llo t=2;
		cc[1]=l;
		cc[2]=r;
		pp[1]=n;
		pp[2]=m;
     // for(llo i = 1; i <= t; i++) cin >> cc[i] >> pp[i], normalize(cc[i], pp[i]);
    ans = cc[1];
    lcm2 = pp[1];
    for(llo i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lcm2, pp[i]);
        llo x1 = pom.x;
        llo d = pom.d;
        if((cc[i] - ans) % d != 0) return -1;
        ans = normalize(ans + x1 * (cc[i] - ans) / d % (pp[i] / d) * lcm2, lcm2 * pp[i] / d);
        lcm2 = LCM(lcm2, pp[i]); // you can save time by replacing above lcm * pp[i] /d by lcm = lcm * pp[i] / d
    }
    return ans;
 //   cout << ans << " " << lcm << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
		vis[aa[i]]=i+1;
	}
	vector<llo> xx;
	gg=__gcd(n,m);
	nn=n/gg;
	mm=m/gg;
	for(llo i=0;i<m;i++){
		cin>>bb[i];
		if(vis[bb[i]]>0){
			xx.pb(solve(vis[bb[i]]-1,i));
			if(xx.back()==-1){
				xx.pop_back();
			}
			/*else{
				cout<<(xx.back())<<endl;
			}*/
		}
	}
	llo ac=nn*mm*gg;
	llo ans=(k-1)%((ac-(llo)(xx.size())));
	llo cur2=(k-1)/((ac-(llo)(xx.size())));
	cur2*=ac;
	ans++;
	vector<pair<llo,llo>> cur;
//	cout<<cur2<<"::"<<endl;

	//cout<<ans<<endl;
	if(xx.size()==0){
		cur.pb({0,ac-1});
	}
	else{
			sort(xx.begin(),xx.end());

		/*map<llo,llo> ss;
		for(auto j:xx){
			ss[j]++;
		}
		llo ind=j;*/
		
		if(xx[0]>0){
			cur.pb({0,xx[0]-1});
		}
		for(llo i=0;i+1<xx.size();i++){
			if(xx[i]+1<xx[i+1]){
				cur.pb({xx[i]+1,xx[i+1]-1});
			}
		}
		if(xx.back()+1<ac){
			cur.pb({xx.back()+1,ac-1});
		}
		


	}
	llo le=ans;
		llo cot=-1;
	/*	for(auto j:cur){
			cout<<j.a<<",,"<<j.b<<endl;
		}*/
		for(auto j:cur){
			if(j.b-j.a+1<le){
				le-=(j.b-j.a+1);
				continue;
			}
			cot=j.a+le-1;
			break;
		}
		cout<<cot+cur2+1<<endl;







 
	return 0;
}