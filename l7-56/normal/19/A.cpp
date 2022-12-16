#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int maxn = 60;

struct Team{
	int score,netgoal,goal;
	string name;
	friend bool operator < (Team a, Team b){
		if(a.score == b.score){
			if(a.netgoal == b.netgoal)
				return a.goal > b.goal;
			return a.netgoal > b.netgoal;
		}
		return a.score > b.score;
	}
}t[maxn];
string u[maxn];
int n,cnt;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		cin >> t[i].name;
	getchar();
	for(int _ = n * (n - 1) / 2; _--;){
		string s1, s2, ss; int x1 = -1, x2 = -1, n1 = 0, n2 = 0;
		getline(cin, ss);
		int p = 0;
		for(; p < (int)ss.size() && ss[p] != '-'; ++p)	s1 += ss[p];
		for(++p; p < (int)ss.size() && isalpha(ss[p]); ++p) s2 += ss[p];
		while(p < (int)ss.size() && !isdigit(ss[p])) ++p;
		while(p < (int)ss.size() && isdigit(ss[p])) n1 = (n1 << 1) + (n1 << 3) + ss[p] - 48, ++p;
		while(p < (int)ss.size() && !isdigit(ss[p])) ++p;
		while(p < (int)ss.size() && isdigit(ss[p])) n2 = (n2 << 1) + (n2 << 3) + ss[p] - 48, ++p;
		//scan
		for(int i = 1; i <= n && (x1 == -1 || x2 == -1); ++i){
			if(t[i].name == s1) x1 = i;
			if(t[i].name == s2) x2 = i;
		}
		t[x1].goal += n1, t[x2].goal += n2, t[x1].netgoal += n1 - n2, t[x2].netgoal += n2 - n1;
		if(n1 > n2) t[x1].score += 3;
		else if(n1 < n2) t[x2].score += 3;
		else t[x1].score++, t[x2].score++;
		//compute
	}
	
	sort(t + 1, t + n + 1);
	for(int i = 1; i <= n / 2; ++i)
		u[++cnt] = t[i].name;
	sort(u + 1, u + cnt + 1);
	
	for(int i = 1; i <= cnt; ++i)
		cout << u[i] << endl;
	
	return 0;
}
// CF19A
/*
4
T
A
b
E
A-T 37:34
b-T 38:99
b-A 33:84
E-T 79:34
E-A 24:37
E-b 3:6
*/