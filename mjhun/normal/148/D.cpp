#include <cstdio>
using namespace std;

double p[1024][1024];
double d[1024][1024];

int main(){
	int i,w,b;
	double pw;
	for(i=0;i<=1000;++i){
		p[i][0]=1;
		p[0][i]=0;
		d[i][0]=1;
		d[0][i]=1;
	}
	for(w=1;w<=1000;++w){
		for(b=1;b<=1000;++b){
			pw=(double)w/(w+b);
			p[w][b]=pw+(1-pw)*(1-d[w][b-1]);
			d[w][b]=pw+(1-pw)*(((double)w/(w+b-1))*(1-p[w-1][b-1])+((double)(b-1)/(w+b-1))*(1-p[w][b-2]));
		}
	}
	scanf("%d %d",&w,&b);
	printf("%.9f\n",p[w][b]);
	return 0;
}