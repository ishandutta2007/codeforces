#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)
using namespace std;
typedef long long ll;


int n;
int x[128];
pair<int,int> xx[128];
vector<string> sol;

string z(){
	string r="";
	fore(i,0,n)r.pb('0');
	return r;
}

bool ready(){
	fore(i,0,n)xx[i].fst=-x[i],xx[i].snd=i;
	sort(xx,xx+n);
	return xx[0].fst==xx[n-1].fst;
}

void doit(){
	if(n>=4&&xx[0].fst==xx[1].fst&&xx[1].fst==xx[2].fst&&xx[0].fst+1==xx[3].fst&&xx[0].fst+1==xx[n-1].fst){
		string s=z();
		s[xx[0].snd]=s[xx[1].snd]=s[xx[2].snd]='1';
		x[xx[0].snd]--;x[xx[0].snd]=max(x[xx[0].snd],0);
		x[xx[1].snd]--;x[xx[1].snd]=max(x[xx[1].snd],0);
		x[xx[2].snd]--;x[xx[2].snd]=max(x[xx[2].snd],0);
		sol.pb(s);
		return;
	}
	string s=z();
	s[xx[0].snd]=s[xx[1].snd]='1';
	x[xx[0].snd]--;x[xx[0].snd]=max(x[xx[0].snd],0);
	x[xx[1].snd]--;x[xx[1].snd]=max(x[xx[1].snd],0);
	sol.pb(s);
}

int main() {
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	while(!ready()){
		doit();
	}
	printf("%d\n",-xx[0].fst);
	printf("%d\n",sol.size());
	fore(i,0,sol.size()){
		printf("%s\n",sol[i].c_str());
	}
	return 0;
}