#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000001];
bool f2;
int b0;
int b1;
int b2;
vector<pair<int,int> > m;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) {
		if(s[i]=='0') {
			b0++;
			if(b2>0) {
				m.push_back(make_pair(b2,2));
				b2=0;
			}
		}
		if(s[i]=='1') b1++;
		if(s[i]=='2') {
			b2++;
			if(b0>0) {
				m.push_back(make_pair(b0,0));
				b0=0;
			}
		}
	}
	if(b0>0) {
		m.push_back(make_pair(b0,0));
		b0=0;
	}
	if(b2>0) {
		m.push_back(make_pair(b2,2));
		b2=0;
	}
	for(int i=0;i<m.size();i++) {
		if(m.size()>0 && m[i].second==2) {
			while(b1>0) {
				printf("1");
				b1--;
			}
		}
		while(m[i].first>0) {
			printf("%d",m[i].second);
			m[i].first--;
		}
	}
	while(b1>0) {
		printf("1");
		b1--;
	}
	return 0;
}