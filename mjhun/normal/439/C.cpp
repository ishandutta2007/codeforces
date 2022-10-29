#include <cstdio>
using namespace std;

int e[100005];
int o[100005];

bool pos(int ne,int no,int k,int p){
    if(no%2!=(k-p)%2)return false;
    if(no<k-p)return false;
    if(ne>=p)return true;
    int q=p-ne;
    if(no>=q*2&&ne+no-q>=k)return true;
    return false;
}

int main(){
    int n,ne=0,no=0,k,p,q,i;
    scanf("%d%d%d",&n,&k,&p);
    for(i=0;i<n;++i){
        scanf("%d",&q);
        if(q%2)o[no++]=q;
        else e[ne++]=q;
    }

    if(!pos(ne,no,k,p))puts("NO");
    else {
        int ie=0,io=0;
        puts("YES");
        for(i=0;i<k-p;++i)
            if(i!=k-1)
                printf("1 %d\n", o[io++]);

        for(i=0;i<p-1;++i){
            if(ie<ne-1){
                printf("1 %d\n", e[ie++]);
            }
            else {
                printf("2 %d %d\n", o[io++], o[io++]);
            }
        }

        printf("%d",ne-ie+no-io);
        while(ie<ne){
            printf(" %d", e[ie++]);
        }
        while(io<no){
            printf(" %d", o[io++]);
        }
        puts("");
    }

    return 0;
}