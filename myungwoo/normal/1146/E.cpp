#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

const int X = 100000;
int N, Q;
int A[MAXN];

void apply(int&, int);

struct NODE {
    NODE(): status(0), left(0), right(0) {}
    int status;
    NODE *left, *right;
    void propagation(){
        if (!this->left) return;
        apply(this->left->status, this->status);
        apply(this->right->status, this->status);
        this->status = 0;
    }
} *root;

NODE* make_tree(int s, int e)
{
    NODE *ret = new NODE();
    if (s == e){
        ret->status = 1;
        return ret;
    }
    int m = s+e >> 1;
    ret->left = make_tree(s, m);
    ret->right = make_tree(m+1, e);
    return ret;
}

void apply(int &a, int b)
{
    if (!b) return;
    if (b == 2){
        if (a == 2) a = 0;
        else if (!a) a = 2;
        else a *= -1;
    }
    else a = b;
}

void flip(NODE* now, int s, int e, int l, int r)
{
    if (e < l || s > r) return;
    if (l <= s && e <= r){
        apply(now->status, 2);
        return;
    }
    now->propagation();
    int m = s+e >> 1;
    flip(now->left, s, m, l, r);
    flip(now->right, m+1, e, l, r);
}

void flipset(NODE* now, int s, int e, int l, int r, int fliped)
{
    if (e < l || s > r) return;
    if (l <= s && e <= r){
        now->status = fliped;
        return;
    }
    now->propagation();
    int m = s+e >> 1;
    flipset(now->left, s, m, l, r, fliped);
    flipset(now->right, m+1, e, l, r, fliped);
}

int get(NODE* now, int s, int e, int t)
{
    if (s == e) return now->status;
    now->propagation();
    int m = s+e >> 1;
    if (t <= m) return get(now->left, s, m, t);
    else return get(now->right, m+1, e, t);
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    root = make_tree(-X, X);
    for (int ts=1;ts<=Q;ts++){
        char c; int v; scanf(" %c%d", &c, &v);
        if (c == '>'){
            if (v >= 0){
                flipset(root, -X, X, v+1, X, -1);
                flipset(root, -X, X, -X, -v-1, 1);
            }else{
                flipset(root, -X, X, -v, X, -1);
                flipset(root, -X, X, -X, v, 1);
                flip(root, -X, X, v+1, -v-1);
            }
        }else{
            if (v <= 0){
                flipset(root, -X, X, -X, v-1, -1);
                flipset(root, -X, X, -v+1, X, 1);
            }else{
                flipset(root, -X, X, v, X, 1);
                flipset(root, -X, X, -X, -v, -1);
                flip(root, -X, X, -v+1, v-1);
            }
        }
    }
    for (int i=1;i<=N;i++){ 
        int negation = get(root, -X, X, A[i]);
        printf("%d%s", A[i]*negation, i < N ? " " : "\n");
    }
}