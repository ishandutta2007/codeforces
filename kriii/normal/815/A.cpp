#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,m,r[101][101];

	scanf ("%d %d",&n,&m);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf ("%d",&r[i][j]);
	int mn = r[0][0];
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (mn > r[i][j]) mn = r[i][j];
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) r[i][j] -= mn;

	vector<int> R,C;
	while (1){
		bool upd = false;

		vector<int> rmn,cmn;
		for (int i=0;i<n;i++){
			int mn = r[i][0];
			for (int j=0;j<m;j++) if (mn > r[i][j]) mn = r[i][j];
			rmn.push_back(mn);
		}
		for (int i=0;i<m;i++){
			int mn = r[0][i];
			for (int j=0;j<n;j++) if (mn > r[j][i]) mn = r[j][i];
			cmn.push_back(mn);
		}

		for (int i=0;i<n;i++) for (int j=0;j<m;j++){
			if (upd) break;
			if (rmn[i] == 0 && cmn[j] > 0){
				for (int k=0;k<n;k++) r[k][j] -= cmn[j];
				while (cmn[j]--) C.push_back(j);
				upd = true;
			}
			else if (rmn[i] > 0 && cmn[j] == 0){
				for (int k=0;k<m;k++) r[i][k] -= rmn[i];
				while (rmn[i]--) R.push_back(i);
				upd = true;
			}
		}
		if (!upd) break;
	}

	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (r[i][j]){
		puts("-1");
		return 0;
	}

	int ans = mn * min(n,m) + R.size() + C.size();
	printf ("%d\n",ans);

	for (int i=0;i<mn;i++){
		if (n < m) for (int j=0;j<n;j++) printf ("row %d\n",j+1);
		else for (int j=0;j<m;j++) printf ("col %d\n",j+1);
	}
	for (int x : R) printf ("row %d\n",x+1);
	for (int x : C) printf ("col %d\n",x+1);

	return 0;
}