/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef complex<double> point;

bool mark[1<<20];
int cnt[1<<20],a[1<<20],b[1<<20],func[1<<20],have[1<<20];

int main(){
	int n,m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; i++){
		int temp;
		scanf("%d", &temp);
		mark[temp] = true;
	}
	for (int i=1; i<=n; i++)
		cnt[i] = cnt[i-1] + mark[i];
	for (int i=1; i<=n; i++){
		if (mark[i])
			func[i] = 1;
		else{
			if (cnt[i] == 0)
				func[i] = -1;
			else
				func[i] = func[i-cnt[i]] + 1;
		}
	}
	int len = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		if (a[i] == -1){
			len-= cnt[len];
		}else{
			len++;
			b[i] = len;
		}
		have[i] = have[i-1] + (a[i] == -1);
	}
	bool flag = false;
	for (int i=0; i<n; i++) if (a[i]!=-1){
		if ((func[b[i]]==-1) || (func[b[i]] > have[n-1] - have[i])){
			printf("%d", a[i]);
			flag = true;
		}
	}
	if (!flag)
		puts("Poor stack!");
	else
		puts("");
	return 0;
}