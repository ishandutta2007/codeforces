#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[300000];
char s[300000];
vector<long long> v;
int main() {
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%s",s);
	v.push_back(a[0]);
	int l;
	long long result=0;
	for(int i=1;i<n;i++) {
		if(s[i]==s[i-1]) v.push_back(a[i]);
		else {
			sort(v.begin(),v.end());
			l=v.size();
			for(int j=l-1;j>=l-k && j>=0;j--) result+=v[j];
			v.clear();
			v.push_back(a[i]);
		}
		//cout<<result<<" "<<v.size()<<endl;
	}
	sort(v.begin(),v.end());
	l=v.size();
	for(int j=l-1;j>=l-k && j>=0;j--) result+=v[j];
	v.clear();
	printf("%lld",result);
	return 0;
}