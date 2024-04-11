#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

multiset<int> s1,s2;
set<int> w1,w2;

int n1,n2,m;

void add(set<int>& w, multiset<int>& s, int x){
	auto it=w.upper_bound(x);
	int b=*it;
	int a=*(--it);
	s.erase(s.find(b-a));
	s.insert(x-a);
	s.insert(b-x);
	w.insert(x);
}

int main(){
	scanf("%d%d%d",&n1,&n2,&m);
	w1.insert(0);w1.insert(n1);s1.insert(n1);
	w2.insert(0);w2.insert(n2);s2.insert(n2);
	while(m--){
		char s[4];int x;
		scanf("%s%d",s,&x);
		if(s[0]=='V')add(w1,s1,x);
		else add(w2,s2,x);
		printf("%lld\n",1LL*(*s1.rbegin())*(*s2.rbegin()));
	}
	return 0;
}