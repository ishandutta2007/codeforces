#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

set <int> S[100010];
vector <Pi> ans;

void add(int s,int d){ans.push_back(Pi(s,d));}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        S[x].insert(i);
    }
    for(i=1;i<=1e5;i++){
        if(S[i].empty())continue;
        if((int)S[i].size() == 1){add(i,0);continue;}
        set<int>::iterator it, jt;
        int d = -1;
        it = S[i].begin();
        jt = it;
        ++it;
        d = *it - *jt;
        bool flag = 0;
        for(;it!=S[i].end();++it,++jt){
            if(d != *it - *jt){flag = 1;break;}
        }
        if(!flag)add(i,d);
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++)printf("%d %d\n",ans[i].X, ans[i].Y);
    return 0;
}