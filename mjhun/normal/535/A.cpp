#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

string s0[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string s1[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main(){
	int n;
	scanf("%d",&n);
	string r;
	if(n<20)r=s0[n];
	else if(n%10==0)r=s1[n/10];
	else r=s1[n/10]+"-"+s0[n%10];
	puts(r.c_str());
	return 0;
}