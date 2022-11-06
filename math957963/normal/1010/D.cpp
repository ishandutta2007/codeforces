#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 1000001

struct nord{
	int p;
	int l;
	int r;
	bool v;
	bool w;
};
nord a[N];

bool dfsv(int k){
	bool v1, v2;
	if (a[k].p == 0)return a[k].v;
	else if (a[k].p == 4){
		v1 = dfsv(a[k].l);
		if (!v1)a[k].v = true;
		else a[k].v = false;
		return a[k].v;
	}
	else{
		v1 = dfsv(a[k].l);
		v2 = dfsv(a[k].r);
		if (a[k].p == 1){
			if (v1&&v2)a[k].v = true;
			else a[k].v = false;
		}
		else if (a[k].p == 2){
			if (v1||v2)a[k].v = true;
			else a[k].v = false;
		}
		else if (a[k].p == 3){
			if (v1&&!v2)a[k].v = true;
			else if (!v1&&v2)a[k].v = true;
			else a[k].v = false;
		}
		return a[k].v;
	}
	return 0;
}

void dfsw(int k){
	if (!a[k].w){
		if (a[k].p == 4){
			a[a[k].l].w = false;
			dfsw(a[k].l);
		}
		else if (a[k].p != 0){
			a[a[k].l].w = false;
			a[a[k].r].w = false;
			dfsw(a[k].l);
			dfsw(a[k].r);
		}
	}
	else{
		if (a[k].p == 4){
			a[a[k].l].w = true;
			dfsw(a[k].l);
		}
		else if (a[k].p == 1){
			if (a[a[k].l].v&&a[a[k].r].v){
				a[a[k].l].w = true;
				a[a[k].r].w = true;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
			else if (a[a[k].l].v&&!a[a[k].r].v){
				a[a[k].l].w = false;
				a[a[k].r].w = true;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
			else if (!a[a[k].l].v&&a[a[k].r].v){
				a[a[k].l].w = true;
				a[a[k].r].w = false;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
			else if (!a[a[k].l].v&&!a[a[k].r].v){
				a[a[k].l].w = false;
				a[a[k].r].w = false;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
		}

		else if (a[k].p == 2){
			if (!a[a[k].l].v&&!a[a[k].r].v){
				a[a[k].l].w = true;
				a[a[k].r].w = true;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
			else if (!a[a[k].l].v&&a[a[k].r].v){
				a[a[k].l].w = false;
				a[a[k].r].w = true;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
			else if (a[a[k].l].v&&!a[a[k].r].v){
				a[a[k].l].w = true;
				a[a[k].r].w = false;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
			else if (a[a[k].l].v&&a[a[k].r].v){
				a[a[k].l].w = false;
				a[a[k].r].w = false;
				dfsw(a[k].l);
				dfsw(a[k].r);
			}
		}

		else if (a[k].p == 3){
			a[a[k].l].w = true;
			a[a[k].r].w = true;
			dfsw(a[k].l);
			dfsw(a[k].r);
		}

	}
	return;
}

int main(){
	char b[10];
	int n, k;
	int x, y, z;
	long long s, ans;
	ans = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%s", b);
		if (b[0] == 'A'){
			scanf("%d %d", &x, &y);
			x--;
			y--;
			a[i].p = 1;
			a[i].l = x;
			a[i].r = y;
		}
		else if (b[0] == 'O'){
			scanf("%d %d", &x, &y);
			x--;
			y--;
			a[i].p = 2;
			a[i].l = x;
			a[i].r = y;
		}
		else if (b[0] == 'X'){
			scanf("%d %d", &x, &y);
			x--;
			y--;
			a[i].p = 3;
			a[i].l = x;
			a[i].r = y;
		}
		else if (b[0] == 'N'){
			scanf("%d", &x);
			x--;
			a[i].p = 4;
			a[i].l = x;
		}
		else{
			scanf("%d", &x);
			a[i].p = 0;
			if(x==1)a[i].v = true;
			else a[i].v = false;
		}
	}
	dfsv(0);
	a[0].w = true;
	dfsw(0);

	if (a[0].v){
		x = 1;
		y = 0;
	}
	else {
		x = 0;
		y = 1;
	}

	f(i, n){
		if (a[i].p == 0){
			if (a[i].w){
				printf("%d", y);
			}
			else{
				printf("%d", x);
			}
		}
	}


	return 0;
}