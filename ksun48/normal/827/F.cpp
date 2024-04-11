#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;

multiset<int> times[1100000];
vector<int> wait[1100000]; // edges which are waiting at some vertex

vector<int> st, en, l, r;
vector<int> ans;

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, lin, rin;
		cin >> a >> b >> lin >> rin;
		a--;
		b--;
		for(int p = 0; p < 2; p++){
			int l1 = lin;
			int r1 = rin;
			if(l1 % 2 != p) l1++;
			if(r1 % 2 == p) r1--;
			if(l1 > r1) continue;

			for(int f = 0; f < 2; f++){
				st.push_back(a+n*p);
				en.push_back(b+n*(1-p));
				l.push_back(l1);
				r.push_back(r1);
				ans.push_back(-1000);
				swap(a,b);
			}
		}
	}
	st.push_back(1010101);
	en.push_back(0);
	l.push_back(-1);
	r.push_back(0);
	ans.push_back(-1000);

	times[1010101].insert(-1);
	priority_queue<pair<int,int> > process; // list of edges (-t, [-1-i for insert] / [i for delete] )
	for(int i = 0; i < st.size(); i++){
		process.push(make_pair(-l[i],i)); // insert at time l
	}
	int finalans = 2e9;
	while(!process.empty()){
		if(!times[n-1].empty() || !times[n-1+n].empty()) break;
		pair<int,int> cur = process.top();
		process.pop();
		int t = -cur.first;
		int type = (cur.second >= 0) ? 1 : 2; // 1 = insert, 2 = remove
		int id = max(cur.second, -1-cur.second);

		//cout << t << " " << type << " " << "s " << st[id] << " e " << en[id] << " l " << l[id] << " r " << r[id] << endl;
		if(type == 1){
			if(t+1 > r[id]) continue;
			if(!times[st[id]].empty()){ // can go there
				int mintime = *times[st[id]].begin();

				if(mintime <= t){ // use edge right now
					//cout << "use" << endl;
					ans[id] = t;
					times[en[id]].insert(t+1);
					process.push(make_pair(-r[id],-1-id));

					for(int i = 0; i < wait[en[id]].size(); i++){
						process.push(make_pair(t+1,wait[en[id]][i] ) );
					}
					wait[en[id]].clear();

				} else { // push  back into into queue
					//cout << "push" << endl;
					process.push(make_pair(-mintime,id));
				}
			} else { // waitlist
				//cout << "wait" << endl;
				wait[st[id]].push_back(id);
			}
		} else { // remove
			times[en[id]].erase(times[en[id]].find(ans[id]+1));
		}
	}
	if(!times[n-1].empty()){
		finalans = min(finalans, *times[n-1].begin());
	}
	if(!times[n+n-1].empty()){
		finalans = min(finalans, *times[n+n-1].begin());
	}
	if(finalans < 2e9){
		cout << finalans << endl;
	} else {
		cout << -1 << endl;
	}
}