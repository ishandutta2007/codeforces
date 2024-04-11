/*
Shot!

Revelations - of the minds
Destination - changing all the times
Pave the way - speed of light
Here to stay - can not fear this fight or get it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

A situation - coming strong
From a nation - spinning worlds along
Don't ya see this new world life?
Can not beat it
Can not tear it down to make it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

Shot!

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!
Generation day... Shot!
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n;
string st;
vector<int> order;

int eval(string st){
	int res=0;
	for (int i=0;i<st.size();i++){
		int here=st[i]-'a';
		res^=(1<<here);
	}
	return res;
}

int query(int val){
	return upper_bound(order.begin(),order.end(),val)-lower_bound(order.begin(),order.end(),val);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	getline(cin,st);

	for(int i=1;i<=n;i++){
		getline(cin,st);
		int mask=eval(st);
		order.push_back(mask);
	}

	sort(order.begin(),order.end());

	long long ans=0;
	for (int i=0;i<order.size();i++){
		ans+=(query(order[i])-1);
		for (int j=0;j<26;j++){
			ans+=query(order[i]^(1<<j));
		}
	}

	cout<<ans/2<<endl;


//	cin.get(); cin.get();
	return 0;
}