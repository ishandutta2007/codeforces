#include<bits/stdc++.h>
using namespace std;
int k1,k2,k3;
map<int,int> s;
int main()
{
	scanf("%d%d%d",&k1,&k2,&k3);
	s[k1]++;
	s[k2]++;
	s[k3]++;
	if(s[1]>=1||s[2]>=2||s[3]>=3||(s[2]>=1&&s[4]>=2)) printf("YES\n");
	else printf("NO\n");
	return 0;
}