#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
char s[maxn];
int n;
vector<int> op;
vector<int> cl;
int main() {
    scanf("%s",s);
    n=strlen(s);
    int i=0,j=n-1;
    int k=0;
    while(i<j) {
        while(i<j && s[i]!='(') i++;
        while(i<j && s[j]!=')') j--;
        if(i<j) {
            op.push_back(i);
            cl.push_back(j);
            i++;
            j--;
            k++;
        }
    }
    if(op.size()==0) {
        printf("0");
        return 0;
    }
    printf("1\n");
    printf("%d\n",2*k);
    for(int i=0;i<k;i++) printf("%d ",op[i]+1);
    for(int i=k-1;i>=0;i--) printf("%d ",cl[i]+1);
    return 0;
}