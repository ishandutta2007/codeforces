#include <stdio.h>
#include <vector>
using namespace std;

int N,K;
vector <int> list[9999];

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=N;i>0;i--) if (i*(i-1)/2 <= N){
        for (j=1;j<=i;j++) for (k=j+1;k<=i;k++){
            list[j].push_back(++K);
            list[k].push_back(K);
        }
        printf("%d\n",i);
        for (j=1;j<=i;j++,puts("")) for (k=0;k<list[j].size();k++) printf("%d ",list[j][k]);
        break;
    }
}