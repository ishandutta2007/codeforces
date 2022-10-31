#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAXN 200000
char s[MAXN+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
vector<pair<int,int> > vec;
int n,a,b,k;
int main(){
   Read(n),Read(a),Read(b),Read(k);
    scanf("%s", s+1);
    s[0] = '1';
    s[n+1] = '1';
    for(int i=0;i<=n;){
        int nex = i+1;
        while(s[nex] != '1')
            nex++;
        if(nex-i-1>=b)
            vec.push_back(make_pair(nex-i-1, nex));
        i = nex;
    }
    vector<int> x;
    int ans = 0, sum = 0;
    for(int i=0;i<vec.size();i++)
        sum += vec[i].first/b;
    for(int i=0;i<vec.size();i++){
        if(sum-vec[i].first/b<a){
            int ti = sum - a + 1;
            ans += ti;
            for(int j=1;j<=ti;j++)
                x.push_back(vec[i].second-j*b);
            break;
        }
		else{
            int ti = vec[i].first/b;
            for(int j=1;j<=ti;j++)
                x.push_back(vec[i].second-j*b);
            sum -= ti;
            ans += ti;
        }
    }
    printf("%d\n", x.size());
    int sz = x.size();
    for(int i=1;i<=sz;i++)
        printf("%d ", x[i-1]);

    return 0;
}