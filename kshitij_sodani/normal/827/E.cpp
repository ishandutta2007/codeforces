//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
/*#define a first 
#define b second*/
#define endl '\n'

using cd = complex<double>;
const double PI = acos(-1);
// llo n;
void fft(vector<cd> & a, bool invert) {
    llo n = a.size();
 
    for (llo i = 1, j = 0; i < n; i++) {
        llo bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (llo len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (llo i = 0; i < n; i += len) {
            cd w(1);
            for (llo j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<llo> multiply(vector<llo> const& a, vector<llo> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    llo n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (llo i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<llo> result(n);
    for (llo i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
vector<llo> pre[500001];
llo vis[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	for(int i=1;i<=500000;i++){
		for(int j=i;j<=500000;j+=i){
			pre[j].pb(i);
		}
	}
	while(t--){
		llo n;
		cin>>n;
		string s;
		cin>>s;
		vector<llo> aa;
		vector<llo> bb;
		for(llo i=0;i<=2*n;i++){
			aa.pb(0);
			bb.pb(0);
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(llo i=0;i<n;i++){
			if(s[i]=='V'){
				aa[n+i]=1;
				//aa.pb(i);
			}	
			else if(s[i]=='K'){
				bb[n-i]=1;
				//bb.pb(i);
			}
		}
		vector<llo> cc=multiply(aa,bb);
		set<llo> cur;
	/*	for(auto j:aa){
			cout<<j<<",";
		}
		cout<<endl;
		for(auto j:bb){
			cout<<j<<",";
		}
		cout<<endl;
		for(auto j:cc){
			cout<<j<<",";
		}
		cout<<endl;*/
		for(llo i=0;i<=4*n;i++){
			if(cc[i]!=0){

				llo x=abs(i-2*n);
				//cout<<x<<"."<<endl;
				//cur.insert(x);
				for(auto j:pre[x]){
					vis[j]=1;
					//cur.insert(j);
				}
				/*if((x%2)==0 and x<=n and x>=1){
					cur.insert(x/2);
				}*/
			}
		}
		llo cot=0;
		for(llo i=1;i<=n;i++){
			if(vis[i]==0){
				cot++;
			}
		}
		cout<<cot<<endl;
		for(llo i=1;i<=n;i++){
			if(vis[i]==0){
				cout<<i<<" ";
			}
		}
		cout<<endl;





	}










 
 
	return 0;
}