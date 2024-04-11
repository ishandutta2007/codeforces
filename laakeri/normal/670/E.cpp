#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int pr[505050];
int n,m,p;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>p;
	cin>>s;
	set<int> h;
	for (int i=0;i<n;i++){
		h.insert(i);
	}
	vector<int> st;
	for (int i=0;i<n;i++){
		if (s[i]=='('){
			st.push_back(i);
		}
		else{
			pr[st.back()]=i;
			pr[i]=st.back();
			st.pop_back();
		}
	}
	int pos=p-1;
	string qq;
	cin>>qq;
	for (int i=0;i<(int)qq.size();i++){
		if (qq[i]=='L'){
			auto it=h.lower_bound(pos);
			it--;
			pos=*it;
		}
		else if(qq[i]=='R'){
			pos=*(h.upper_bound(pos));
		}
		else{
			int le=min(pr[pos], pos);
			int ri=max(pr[pos], pos);
			while (1){
				auto it=h.lower_bound(le);
				if (it==h.end()||(*it)>ri) break;
				h.erase(it);
			}
			auto it=h.lower_bound(le);
			if (it==h.end()) it--;
			pos=*it;
		}
	}
	string v;
	for (int t:h){
		v+=s[t];
	}
	cout<<v<<endl;
}