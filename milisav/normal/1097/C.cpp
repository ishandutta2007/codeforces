#include<bits/stdc++.h>
using namespace std;
int n;
char s[600000];
map<pair<int,int>,int> mp;
int main()
{
	scanf("%d",&n);
	int m;
	int t=0,r=0;
	int sol=0;
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		m=strlen(s);
		t=0;
		r=0;
		for(int j=0;j<m;j++) {
			if(s[j]=='(') t++;
			if(s[j]==')') t--;
			if(t<r) r=t;
		}
		//cout<<t<<" "<<r<<" "<<mp[make_pair(-t,-t)]<<endl;
		if(t>=0 && r==0 && mp[make_pair(-t,-t)]!=0) {
			sol++;
			mp[make_pair(-t,-t)]--;
		}
		else {
			if(t<=0 && r==t && mp[make_pair(-t,0)]!=0) {
				sol++;
				mp[make_pair(-t,0)]--;
			}
			else mp[make_pair(t,r)]++;
		}
	}
	printf("%d",sol);
	return 0;
}