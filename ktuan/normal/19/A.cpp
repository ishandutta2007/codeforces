#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

struct Team{
	int point,dif,win,id;		
};

int n;
string s[55];
Team a[55];

int get(string ss){
	Rep(i,n)if(s[i]==ss)return i;
}

int toint(string s){
	istringstream iss(s);
	int x;
	iss>>x;
	return x ;	
}

bool cmp(Team a,Team b){
	if(a.point==b.point){
		if(a.dif==b.dif)return a.win>b.win;
		else return a.dif>b.dif;	
	}	
	else return a.point>b.point;
}

int main() {
	cin>>n;
	Rep(i,n)cin>>s[i];
	string ss;
	getline(cin,ss);
	Rep(i,n)a[i].id=i;
	Rep(i,(n*(n-1)/2)){
		getline(cin,ss);
		int p1,p2,p3;
		Rep(i,ss.length()){
			if(ss[i]=='-')p1=i;
			if(ss[i]==' ')p2=i;
			if(ss[i]==':')p3=i;
		}
		string team1=ss.substr(0,p1);
		string team2=ss.substr(p1+1,p2-p1-1);
		string score1=ss.substr(p2+1,p3-p2-1);
		string score2=ss.substr(p3+1);
		int t1=get(team1);
		int t2=get(team2);
		int s1=toint(score1);
		int s2=toint(score2);
		if(s1>s2)a[t1].point+=3;
		else if(s1<s2)a[t2].point+=3;
		else a[t1].point++,a[t2].point++;
		a[t1].dif+=s1-s2;
		a[t2].dif+=s2-s1;
		a[t1].win+=s1;
		a[t2].win+=s2;
	}	
	sort(a,a+n,cmp);
	vector<string> vs;
	Rep(i,n/2)vs.pb(s[a[i].id]);
	sort(vs.begin(),vs.end());
	Rep(i,vs.size())cout<<vs[i]<<endl;
	return 0;	
}