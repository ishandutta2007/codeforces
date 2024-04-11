#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	string s1, s2, s3;
	int c1[100], c2[100], c3[100], m1=0, m2=0, m3=0;
	
	for (int i=0; i<100; i++) c1[i]=0, c2[i]=0, c3[i]=0;
	cin>>s1>>s2>>s3;
	
	for (int i=0; i<s1.size(); i++) 
	{
		if (s1[i]>='A' && s1[i]<='Z') c1[s1[i]-'A']++;
		else if (s1[i]>='a' && s1[i]<='z') c1[s1[i]-'a'+26]++;
		if (s2[i]>='A' && s2[i]<='Z') c2[s2[i]-'A']++;
		else if (s2[i]>='a' && s2[i]<='z') c2[s2[i]-'a'+26]++;
		if (s3[i]>='A' && s3[i]<='Z') c3[s3[i]-'A']++;
		else if (s3[i]>='a' && s3[i]<='z') c3[s3[i]-'a'+26]++;;
	}
	
	for (int i=0; i<52; i++) m1=max(m1, c1[i]), m2=max(m2, c2[i]), m3=max(m3, c3[i]);
	
	if (m1+n<=s1.size()) m1+=n;
	else m1=s1.size()-(n==1 && m1==s1.size());
	if (m2+n<=s2.size()) m2+=n;
	else m2=s2.size()-(n==1 && m2==s2.size());
	if (m3+n<=s3.size()) m3+=n;
	else m3=s3.size()-(n==1 && m3==s3.size());
	
	if (m1>m2 && m1>m3) cout<<"Kuro";
	else if (m2>m1 && m2>m3) cout<<"Shiro";
	else if (m3>m1 && m3>m2) cout<<"Katie";
	else cout<<"Draw";
}