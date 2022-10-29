#include <bits/stdc++.h>
#define M 3162279
using namespace std;

bool np[M+5];
vector<int> ps;


int main(){
	for(int i=2;i<M;++i){
		if(!np[i]){
			ps.push_back(i);
			for(int j=i+i;j<M;j+=i)np[j]=true;
		}
	}
	long long q,p=1;int n=0,k=0;
	cin>>q;
	while(k<ps.size()&&1LL*ps[k]*ps[k]<=q){
		if(q%ps[k]==0){
			q/=ps[k];p*=ps[k];
			n++;
			if(n==2){
				cout<<1<<endl<<p<<endl;
				return 0;
			}
		}
		else k++;
	}
	if(n) cout<<2<<endl;
	else cout<<1<<endl<<0<<endl;
	return 0;
}