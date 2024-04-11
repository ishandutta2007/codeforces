#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

char ch[55][55];
int ans;

int main(){
	int n, m; scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",ch[i]);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			int p[26] = {0};
			p[ch[i][j] - 'a']++;
			p[ch[i+1][j] - 'a']++;
			p[ch[i][j+1] - 'a']++;
			p[ch[1+i][1+j] - 'a']++;
			if(p[0] && p[2] && p[4] && p[5])ans++;
		}
	}
	printf("%d",ans);
	return 0;
}