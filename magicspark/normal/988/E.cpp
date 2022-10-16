#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
string s;
int cnt[10];
int calc(string a,string b){
	int dat[111];
	for(int i=0;i<a.size();i++)for(int j=i+1;j<b.size();j++)if(a[i]==b[j])dat[i]=j;
	int ret=0;
	for(int i=0;i<a.size();i++)for(int j=i+1;j<b.size();j++)if(dat[i]>dat[j])ret++;
	return ret;
}
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)cnt[s[i]-'0']++;
	int ans=inf;
	if(cnt[0]>=2){
		int best=0,cal=0;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='0')best+=(s.size()-1-i),cal++;
			if(cal==2)break;
		}
		best--;
		ans=min(ans,best);
	}
	if(cnt[2]>=1&&cnt[5]>=1){
		string s2=s;
		int best=0;
		for(int i=s.size()-1;i>=0;i--){
			if(s2[i]=='5'){
				for(int j=i;j<s.size()-1;j++)swap(s2[j],s2[j+1]),best++;
				break;
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s2[i]=='2'){
				for(int j=i;j<s.size()-2;j++)swap(s2[j],s2[j+1]),best++;
				break;
			}
		}
		int i;
		for(i=0;i<s2.size()&&s2[i]=='0';i++);
		if(s2.size()-i<3&&s2[0]=='0')best=inf;
		else best+=i;
		ans=min(ans,best);
	}
	if(cnt[5]>=1&&cnt[0]>=1){
		string s2=s;
		int best=0;
		for(int i=s.size()-1;i>=0;i--){
			if(s2[i]=='0'){
				for(int j=i;j<s.size()-1;j++)swap(s2[j],s2[j+1]),best++;
				break;
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s2[i]=='5'){
				for(int j=i;j<s.size()-2;j++)swap(s2[j],s2[j+1]),best++;
				break;
			}
		}
		int i;
		for(i=0;i<s2.size()&&s2[i]=='0';i++);
		if(s2.size()-i<3&&s2[0]=='0')best=inf;
		else best+=i;
		ans=min(ans,best);
	}
	if(cnt[7]>=1&&cnt[5]>=1){
		string s2=s;
		int best=0;
		for(int i=s.size()-1;i>=0;i--){
			if(s2[i]=='5'){
				for(int j=i;j<s.size()-1;j++)swap(s2[j],s2[j+1]),best++;
				break;
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s2[i]=='7'){
				for(int j=i;j<s.size()-2;j++)swap(s2[j],s2[j+1]),best++;
				break;
			}
		}
		int i;
		for(i=0;i<s2.size()&&s2[i]=='0';i++);
		if(s2.size()-i<3&&s2[0]=='0')best=inf;
		else best+=i;
		ans=min(ans,best);
	}
	if(ans==inf){
		puts("-1");
		return 0;
	}
	cout<<ans<<endl;
	return 0;
	#ifndef ONLINE_JUDGE
		printf("-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}