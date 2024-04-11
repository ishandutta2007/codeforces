#include<bits/stdc++.h>
using namespace std;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1035;
int n,x,y,r,used,keep[12];
bool b[12];
void ask(vector<int>  &a){
    used++;
    printf("? %d ",(int)a.size());
    for(int i:a){
        printf("%d " ,i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d", &r);
}
int sum;
vector<int> a;
vector<int> touse;
bool checkbit(int bit){
    a.clear();
    for(int i=1;i<=n; i++){
        if((i>>bit) & 1){
           a.push_back(i);
        }
    }
    ask(a);
    int res = sum ^ r;
    if((r == y) || (r == (x^y))){
        if(touse.empty()){
            touse = a;
        }
        return false;
    }
    if((res == y) || (res == (x^y))){
        if(touse.empty()){
            for(int i=1;i<=n;i++){
                if((i>>bit)^1)
                    touse.push_back(i);
            }
        }
        return false;
    }
    return true;
}

int main(){
    scanf("%d%d%d",&n,&x,&y);
    sum = n&1 ? x:0;
    int bit = 0;
    int msb = 0;
    for(int i=1;i<=10;i++){
        if(n & (1<<i))
            msb = i;
    }
    bit = msb+1;
    int txor = 0;
    for(int i=0;i<bit;i++){
        b[i] = checkbit(i);
        if(!b[i])
        txor ^= (1<<i);
    }
    while((int)touse.size() != 1){
        vector<int> split;
        int sz = ((int)touse.size())/2;
        for(int i=1;i<=sz;i++){
            split.push_back(touse.back());
            touse.pop_back();
            }
        ask(split);
        if((r ==y) || (r== (x^y))){
            touse = split;
        }
    }
    int p1 = touse[0],p2 = p1^txor;
    if(p1>p2){
        swap(p1,p2);
    }
    printf("! %d %d\n",p1,p2);
    fflush(stdout);
}