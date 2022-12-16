#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int N=200005;  
char s[N];  
struct Node {  
    int mat[5][5];  
    Node operator + (Node x) {  
        Node ans;  
        for(int i=0;i<5;++i) {  
            for(int j=0;j<5;++j) {  
                ans.mat[i][j]=N;  
                for(int k=0;k<5;++k) {  
                    ans.mat[i][j]=min(ans.mat[i][j],mat[i][k]+x.mat[k][j]);  
                }  
            }  
        }  
        return ans;  
    }  
}a[N<<2];  
void build(int l,int r,int x) {  
    if(l==r) {  
        for(int i=0;i<5;++i) {  
            for(int j=0;j<5;++j) {  
                a[x].mat[i][j]=(i==j)?0:N;  
            }  
        }  
        if(s[l]=='2') a[x].mat[0][1]=0,a[x].mat[0][0]=1;  
        if(s[l]=='0') a[x].mat[1][2]=0,a[x].mat[1][1]=1;  
        if(s[l]=='1') a[x].mat[2][3]=0,a[x].mat[2][2]=1;  
        if(s[l]=='7') a[x].mat[3][4]=0,a[x].mat[3][3]=1;  
        if(s[l]=='6') a[x].mat[3][3]=1,a[x].mat[4][4]=1;  
        return ;  
    }  
    int m=l+r>>1;  
    build(l,m,x<<1);build(m+1,r,x<<1|1);  
    a[x]=a[x<<1]+a[x<<1|1];   
}  
Node query(int l,int r,int L,int R,int x) {  
    if(L<=l&&r<=R) return a[x];  
    int m=l+r>>1;  
    if(m<L) return query(m+1,r,L,R,x<<1|1);  
    if(m>=R) return query(l,m,L,R,x<<1);  
    return query(l,m,L,R,x<<1)+query(m+1,r,L,R,x<<1|1);  
}  
int main() {  
    int n,q;  
    while(~scanf("%d%d%s",&n,&q,s+1)) {  
        build(1,n,1);  
        while(q--) {  
            int l,r;  
            scanf("%d%d",&l,&r);  
            int ans=query(1,n,l,r,1).mat[0][4];  
            if(ans==N) ans=-1;  
            printf("%d\n",ans);  
        }  
    }  
    return 0;  
}