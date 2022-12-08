#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,sx[55],sy[55],ex[55],ey[55],c[55];
struct inst{
	int a,b,c,d;
};vector<inst> ans;

int main()
{
	scanf ("%d %d",&N,&M);
	if (N == 1){
		puts("0");
		return 0;
	}
	for (int i=1;i<=M;i++) scanf ("%d %d",&sx[i],&sy[i]);
	for (int i=1;i<=M;i++) scanf ("%d %d",&ex[i],&ey[i]),c[ex[i]]++;

	int p = 1; bool emp = false;
	for (int i=1;i<=N;i++){
		if (c[i] == 0){
			if (i == N) p = i-1;
			else p = i;
			emp = true;
			break;
		}
	}

	while (1){
		vector<pair<int, int> > u;
		for (int i=1;i<=M;i++){
			u.push_back({sy[i],i});
		} sort(u.begin(),u.end());
		bool ch = 0;
		for (int i=0;i<M;i++){
			if (i + 1 < u[i].first){
				int &j = u[i].second;
				if (j >= 1){
					ans.push_back({sx[j],sy[j],sx[j],sy[j]-1});
					sy[j]--;
					j = 0;
					ch = true;
				}
			}
		}
		for (int i=M-1;i>=0;i--){
			if (i + 1 > u[i].first){
				int &j = u[i].second;
				if (j >= 1){
					ans.push_back({sx[j],sy[j],sx[j],sy[j]+1});
					sy[j]++;
					j = 0;
					ch = true;
				}
			}
		}
		if (!ch) break;
	}

	for (int i=1;i<=M;i++){
		while (sx[i] > p){
			ans.push_back({sx[i],sy[i],sx[i]-1,sy[i]});
			sx[i]--;
		}
		while (sx[i] < p){
			ans.push_back({sx[i],sy[i],sx[i]+1,sy[i]});
			sx[i]++;
		}
	}

	for (int i=N;i>=p+2;i--){
		for (int j=1;j<=M;j++) if (ex[j] == i){
			ans.push_back({sx[j],sy[j],sx[j]+1,sy[j]});
			sx[j]++;
			while (sy[j] < ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]+1});
				sy[j]++;
			}
			while (sy[j] > ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]-1});
				sy[j]--;
			}
			while (sx[j] < ex[j]){
				ans.push_back({sx[j],sy[j],sx[j]+1,sy[j]});
				sx[j]++;
			}
		}
	}

	for (int i=1;i<=M;i++) if (sx[i] == p){
		ans.push_back({sx[i],sy[i],sx[i]+1,sy[i]});
		sx[i]++;
	}

	for (int i=1;i<=p-1;i++){
		for (int j=1;j<=M;j++) if (ex[j] == i){
			ans.push_back({sx[j],sy[j],sx[j]-1,sy[j]});
			sx[j]--;
			while (sy[j] < ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]+1});
				sy[j]++;
			}
			while (sy[j] > ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]-1});
				sy[j]--;
			}
			while (sx[j] > ex[j]){
				ans.push_back({sx[j],sy[j],sx[j]-1,sy[j]});
				sx[j]--;
			}
		}
	}

	if (emp){
		int u = 1;
		vector<int> ind;
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++) if (sx[j] == p+1 && sy[j] == i){
				while (sy[j] > u){
					ans.push_back({sx[j],sy[j],sx[j],sy[j]-1});
					sy[j]--;
				}
				ind.push_back(j);
				u++;
				break;
			}
		}
		for (int i=0;i<ind.size();i++){
			for (int j=i+1;j<ind.size();j++){
				int &p = ind[j-1], &q = ind[j];
				if (ey[p] > ey[q]){
					ans.push_back({sx[p],sy[p],sx[p]-1,sy[p]});
					ans.push_back({sx[p]-1,sy[p],sx[p]-1,sy[p]+1});
					ans.push_back({sx[q],sy[q],sx[q],sy[q]-1});
					ans.push_back({sx[p]-1,sy[p]+1,sx[p],sy[p]+1});
					sy[p]++; sy[q]--;
					swap(p,q);
				}
			}
		}

		for (int i=(int)ind.size()-1;i>=0;i--){
			int j = ind[i];
			while (sy[j] < ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]+1});
				sy[j]++;
			}
			while (sx[j] > ex[j]){
				ans.push_back({sx[j],sy[j],sx[j]-1,sy[j]});
				sx[j]--;
			}
		}
	}
	else{
		for (int j=1;j<=M;j++) if (ex[j] == p){
			ans.push_back({sx[j],sy[j],sx[j]-1,sy[j]});
			sx[j]--;
			while (sy[j] < ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]+1});
				sy[j]++;
			}
			while (sy[j] > ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]-1});
				sy[j]--;
			}
		}
		for (int j=1;j<=M;j++) if (ex[j] == p+1){
			while (sy[j] < ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]+1});
				sy[j]++;
			}
			while (sy[j] > ey[j]){
				ans.push_back({sx[j],sy[j],sx[j],sy[j]-1});
				sy[j]--;
			}
		}
	}

	printf ("%d\n",ans.size());
	if (ans.size() > 10800) while (1);
	for (auto &p : ans) printf ("%d %d %d %d\n",p.a,p.b,p.c,p.d);
	return 0;
}