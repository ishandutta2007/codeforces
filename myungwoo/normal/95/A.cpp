#include <stdio.h>
#include <string>
using namespace std;

#define num(c) (c>'Z'?c-'a':c-'A')

int N,L;
char let,buf[999];
string words[101],W;
bool chk[999];

void ch(int p,int n)
{
    if (W[p] > 'Z') W[p] = n+'a';
    else W[p] = n+'A';
}

bool issame(string a,string b)
{
    int i,la=a.length(),lb=b.length();
    if (la != lb) return 0;
    for (i=0;i<la;i++) if (num(a[i]) != num(b[i])) return 0;
    return 1;
}

int main()
{
    int i,j,k,l;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%s",buf);
        words[i] = buf;
    }
    scanf("%s",buf);
    W = buf; L = W.length();
    scanf(" %c",&let);
    for (i=1;i<=N;i++){
        l = words[i].length();
        for (j=0;j<=L-l;j++) if (issame(W.substr(j,l),words[i])){
            for (k=j;k<j+l;k++) chk[k] = 1;
        }
    }
    for (i=0;i<L;i++) if (chk[i]){
        if (num(W[i]) == num(let)) ch(i,num(let)?0:1);
        else ch(i,num(let));
    }
    printf("%s",W.c_str());
}