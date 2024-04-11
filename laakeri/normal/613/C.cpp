#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int ok[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> ct(n);
	int tl=0;
	int nn=0;
	int odd=0;
	for (int i=0;i<n;i++){
		cin>>ct[i];
		tl+=ct[i];
		if (ct[i]%2==1) odd++;
		if (ct[i]>0){
			nn++;
			for (int j=1;j<=ct[i];j++){
				if (ct[i]%j==0){
					ok[j]++;
				}
			}
		}
	}
	if (nn<2){
		cout<<tl<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<ct[i];j++){
				cout<<(char)('a'+i);
			}
		}
		cout<<endl;
	}
	else if(odd>1){
		cout<<0<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<ct[i];j++){
				cout<<(char)('a'+i);
			}
		}
		cout<<endl;
	}
	else{
		int bv=1;
		for (int i=1;i<=tl;i++){
			if (ok[i]==nn){
				int x=i;
				int o=0;
				for (int ii=0;ii<n;ii++){
					ct[ii]/=x;
					if (ct[ii]%2==1) o++;
				}
				if (o<2||(i%2==0)){
					bv=max(bv, i);
				}
				for (int ii=0;ii<n;ii++){
					ct[ii]*=x;
				}
			}
		}
		cout<<bv<<endl;
		tl/=bv;
		string r(tl, ' ');
		int of=0;
		for (int ii=0;ii<n;ii++){
			ct[ii]/=bv;
			if (ct[ii]%2==1) of=1;
		}
		if (bv%2==0){
			int i2=0;
			for (int i=0;i<(int)ct.size();i++){
				for (int j=0;j<ct[i];j++){
					r[i2++]=(char)('a'+i);
				}
			}
		}
		else{
			int i2=0;
			if (of){
				for (int i=0;i<(int)ct.size();i++){
					if (ct[i]%2==1) {
						for (int j=0;j<ct[i];j+=2){
							r[tl/2-i2]=(char)('a'+i);
							r[tl/2+i2]=(char)('a'+i);
							i2++;
						}
					}
				}
				for (int i=0;i<(int)ct.size();i++){
					if (ct[i]%2==0) {
						for (int j=0;j<ct[i];j+=2){
							r[tl/2-i2]=(char)('a'+i);
							r[tl/2+i2]=(char)('a'+i);
							i2++;
						}
					}
				}
			}
			else{
				for (int i=0;i<(int)ct.size();i++){
					if (ct[i]%2==0) {
						for (int j=0;j<ct[i];j+=2){
							r[tl/2-i2-1]=(char)('a'+i);
							r[tl/2+i2]=(char)('a'+i);
							i2++;
						}
					}
				}
			}
		}
		string v="";
		for (int i=0;i<bv;i++){
			v=v+r;
			reverse(r.begin(), r.end());
		}
		cout<<v<<endl;
	}
}