#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int cnt2,cnt3,cnt5,cnt7;
int n;
string x;
int v[10][4]={
{0,0,0,0},
{0,0,0,0},
{1,0,0,0},
{1,1,0,0},
{3,1,0,0},
{3,1,1,0},
{4,2,1,0},
{4,2,1,1},
{7,2,1,1},
{7,4,1,1}
};
int main(){
	cin>>n>>x;
	for(char c:x){
		int _=c-'0';
		cnt2+=v[_][0];
		cnt3+=v[_][1];
		cnt5+=v[_][2];
		cnt7+=v[_][3];
	}
	string s="";
	while(cnt7){
		s.push_back('7');
		cnt2-=4;cnt3-=2;cnt5--;cnt7--;
	}
	while(cnt5){
		s.push_back('5');
		cnt5--;cnt3--;cnt2-=3;
	}
	while(cnt3){
		s.push_back('3');
		cnt3--;cnt2--;
	}
	while(cnt2--){
		s.push_back('2');
	}
	cout<<s<<endl;
	return 0;
}