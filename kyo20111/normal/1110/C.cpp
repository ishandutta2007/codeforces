#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,mp[50]={ 0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401, };
int main(){
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int a,fl=0,j=0;
        scanf("%d",&a);
        while((1<<j) <= a){
            if(!((1<<j)&a)) fl=1;
            j++;
        }
        if(fl) printf("%d\n",(1<<j)-1);
        else printf("%d\n",mp[j]);
    }
}