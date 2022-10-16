#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
const long double eps=1e-3;
int a[1001],b[1001];
vector<int> up,down;
int main(){
	int n,m;
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		up.push_back(a[i]-1);
		down.push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		up.push_back(b[i]-1);
		down.push_back(b[i]);
	}
	for(int i=0;i<up.size();i++)
		for(int j=0;j<down.size();j++){
			int x=__gcd(up[i],down[j]);
			up[i]/=x;
			down[j]/=x;
		}
	long double ans=1.0;
	sort(up.begin(),up.end());
	sort(down.begin(),down.end());
	reverse(up.begin(),up.end());
	reverse(down.begin(),down.end());
	for(int i=0;i<up.size();i++){
		//cout<<up[i]<<" "<<down[i]<<" "<<ans<<endl;
		if(down[i]!=1&&down[i]!=0)ans*=(long double)down[i];
		if(up[i]!=1&&up[i]!=0)ans/=(long double)up[i];
	}	
	
	ans=(ans-1)*(long double)m;
	if(ans<=0){
		cout<<-1;
		return 0;
	}
	printf("%.12lf",(double)ans);
	return 0;
}