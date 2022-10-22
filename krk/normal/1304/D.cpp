#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
int A[Maxn], in[Maxn];
int res[Maxn];

void Incr()
{
    priority_queue <int> Q;
    for (int i = 0; i < n; i++) {
        in[i] = A[i];
        if (in[i] == 0) Q.push(-i);
    }
    int pnt = 0;
    while (!Q.empty()) {
        int i = -Q.top(); Q.pop();
        res[i] = ++pnt;
        if (i + 1 < n && str[i] == '<')
            if (--in[i + 1] == 0) Q.push(-(i + 1));
        if (i - 1 >= 0 && str[i - 1] == '>')
            if (--in[i - 1] == 0) Q.push(-(i - 1));
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
}

void Decr()
{
    priority_queue <int> Q;
    for (int i = 0; i < n; i++) {
        in[i] = A[i];
        if (in[i] == 0) Q.push(i);
    }
    int pnt = 0;
    while (!Q.empty()) {
        int i = Q.top(); Q.pop();
        res[i] = ++pnt;
        if (i + 1 < n && str[i] == '<')
            if (--in[i + 1] == 0) Q.push(i + 1);
        if (i - 1 >= 0 && str[i - 1] == '>')
            if (--in[i - 1] == 0) Q.push(i - 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        for (int i = 0; i < n; i++) {
            A[i] = 0;
            if (i + 1 < n && str[i] == '>') A[i]++;
            if (i - 1 >= 0 && str[i - 1] == '<') A[i]++;
        }
        Decr();
        Incr();
    }
    return 0;
}