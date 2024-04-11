#include<cstdio>
#include<set>
#include<utility>
int const nax = 3e5 + 10; 
int n , x[nax], y[nax];
std :: set < std :: pair <int, int>> s;


int main() {
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d %d", & x[i], &y[i]);
    }
    x[n + 1] = x[1], y[n + 1] = y[1];
    for(int i = 1 ; i <= n; i ++){
        int nx = x[i + 1] - x[i], ny = y[i + 1] - y[i];
        s.insert(std :: make_pair(nx, ny));
    }
    x[0] = x[n], y[0] = y[n];
    for(int i = 1 ; i <= n; i ++){
        int nx = x[i - 1] - x[i] ,  ny = y[i - 1] - y[i];
        if(!s.count(std :: make_pair(nx, ny))){
            return !printf("NO");
        }
    }
    printf("YES");
}