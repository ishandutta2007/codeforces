#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL start[200000];
LL end[200000];
LL cur[200000];
vector<LL> edges[200000];
LL vis[200000];
LL wrongn[200000];
LL deg	[200000];
LL wrong[200000];
LL steps1 = 0;
LL steps2 = 0;
LL seq1[500000];
LL seq2[500000];
LL n1, n2;
void move(LL a){
	if(vis[a]) return;
	vis[a] = 1;
	for(LL c = 0; c < edges[a].size(); c++){
		if(cur[a] != 0){
			move(edges[a][c]);
			if(cur[edges[a][c]] == 0){
				//cout << "cur " << edges[a][c] << " " << a << endl;
				swap(cur[edges[a][c]], cur[a]);
				steps1++;
			}
		}
	}
}
void movestart(LL a){
	if(vis[a]) return;
	vis[a] = 1;
	for(LL c = 0; c < edges[a].size(); c++){
		if(start[a] != 0){
			movestart(edges[a][c]);
			if(start[edges[a][c]] == 0 && wrong[edges[a][c]] == 0){
				//cout << "start " << edges[a][c] << " " << a << endl;
				swap(start[edges[a][c]], start[a]);
				steps2++;
			}
		}
	}
}
void moveend(LL a){
	if(vis[a]) return;
	vis[a] = 1;
	for(LL c = 0; c < edges[a].size(); c++){
		if(end[a] != 0){
			moveend(edges[a][c]);
			if(end[edges[a][c]] == 0 && wrong[edges[a][c]] == 0){
				//cout << "end " << edges[a][c] << " " << a << endl;
				swap(end[edges[a][c]], end[a]);
				steps2++;
			}
		}
	}
}
void reset(){
	for(LL i = 0; i < n; i++) vis[i] = 0;
}
void cc(LL a){
	if(vis[a]) return;
	vis[a] = 1;
	for(LL c = 0; c < edges[a].size(); c++){
		if(!wrong[edges[a][c]]){
			cc(edges[a][c]);
		} else {
			wrongn[a]++;
		}
	}
}
vector<LL> seq;
void path(LL a){
	if(vis[a]) return;
	vis[a] = 1;
	seq.push_back(a);
	for(LL c = 0; c < edges[a].size(); c++){
		if(wrong[edges[a][c]]){
			path(edges[a][c]);
		}
	}
}
int main(){
	cin >> n;
	for(LL i = 0; i < n; i++){
		cin >> start[i];
		cur[i] = start[i];
		wrongn[i] = 0;
	}
	reset();
	for(LL i = 0; i < n; i++){
		cin >> end[i];
	}
	for(LL i = 0; i < (n-1); i++){
		LL u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(LL i = 0; i < n; i++){
		if(end[i] == 0){
			move(i);
		}
	}
	LL allright = 1;
	for(LL i = 0; i < n; i++){
		if(cur[i] != end[i]){
			wrong[i] = 1;
			allright = 0;
		}
		//cout << i << " " << cur[i] << " " << end[i] << endl;
	}
	if(allright == 1){
		cout << 0 << " " << steps1 << endl;
		return 0;
	}
	reset();
	for(LL i = 0; i < n; i++){
		if(end[i] == 0){
			cc(i);
		}
	}
	LL nump = 0;
	LL r = -1;
	for(LL i = 0; i < n; i++){
		if(wrongn[i] > 0){
			r = i;
			nump++;
		}
	}
	if(nump > 1){
		cout << -1 << endl;
		return 0;
	}
	wrong[r] = 1;
	LL d1 = 0;
	LL s = -1;
	LL e = -1;
	for(LL i = 0; i < n; i++){
		deg[i] = 0;
		if(wrong[i]){
			for(LL c = 0; c < edges[i].size(); c++){
				if(wrong[edges[i][c]]){
					deg[i]++;
				}
			}
			if(deg[i] >= 3){
				cout << -1 << endl;
				return 0;
			}
			if(deg[i] == 1){
				d1++;
				if(s == -1){
					s = i;
				} else {
					e = i;
				}
			}
			if(deg[i] == 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if(d1 > 2){
		cout << -1 << endl;
		return 0;
	}
	reset();
	movestart(r);
	reset();
	moveend(r);
	reset();
	path(s);
	for(LL i = 0; i < seq.size(); i++){
		//cout << seq[i] << " " << start[seq[i]] << " " << end[seq[i]] << endl;
		if(start[seq[i]] != 0){
			seq1[n1++] = start[seq[i]];
		}
		if(end[seq[i]] != 0){
			seq2[n2++] = end[seq[i]];
		}
	}
	for(LL i = 0; i < seq.size(); i++){
		if(end[seq[i]] != 0){
			seq2[n2++] = end[seq[i]];
		}
	}
	/*for(LL i = 0; i < n1; i++){
		cout << seq1[i] << " ";
	}
	cout << endl;
	for(LL i = 0; i < n2; i++){
		cout << seq2[i] << " ";
	}
	cout << endl;*/
	LL works = 0;
	for(LL i = 0; i < n2/2; i++){
		if(seq1[0] == seq2[i]){
			LL fine = 1;
			for(LL j = 0; j < n1; j++){
				if(seq1[j] != seq2[i+j]){
					fine = 0;
				}
			}
			if(fine){
				works = 1;
			}
		}
	}
	if(!works){
		cout << -1 << endl;
		return 0;
	}
	LL l = seq.size();
	LL zz;
	for(LL i = 0; i < l; i++){
		if(start[seq[i]] == 0){
			zz = i;
		}
	}
	LL nq = 0;
	while(end[seq[zz]] != 0){
		nq++;
		swap(start[seq[zz]], start[seq[(zz+1)%l]]);
		zz = (zz+1)%l;
	}
	LL q;
	for(LL i = 0; i < l; i++){
		if(end[seq[i]] == start[seq[(zz+l-1)%l]]){
			q = i;
		}
	}
	nq += l*((zz-1-q+l)%l);
	nq = min(nq, l*(l-1)-nq);
	cout << s+1 << " " << e+1 << " " << steps2+nq << endl;
}