#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n;
int A[N];

struct Node {
    int nodes;
    Node *left;
    Node *right;
};

Node *root;

void wypiszBity(vector<int> v) {
    reverse(v.begin(), v.end());
    for (int x : v) {
        cerr << x;
    }
}

void insert(Node *w, vector<int> &bits) {
    w->nodes++;
    if (bits.empty()) {
        return;
    }
    if (bits.back() == 0) {
        if (w->left == NULL) {
            w->left = new Node;
            w->left->nodes = 0;
            w->left->left = NULL;
            w->left->right = NULL;
        }
        bits.pop_back();
        insert(w->left, bits);
    } else {
        if (w->right == NULL) {
            w->right = new Node;
            w->right->nodes = 0;
            w->right->left = NULL;
            w->right->right = NULL;
        }
        bits.pop_back();
        insert(w->right, bits);
    }
}

int query(Node *w, vector<int> &bits, int depth) {
    w->nodes--;
    if (bits.empty()) {
        return 0;
    }
    int value = 0;
    Node *to;
    if (bits.back() == 0) {
        to = w->left;
        if (w->left == NULL || w->left->nodes == 0) {
            to = w->right;
            value = 1;
        }
    } else if (bits.back() == 1) {
        value = 1;
        to = w->right;
        if (w->right == NULL || w->right->nodes == 0) {
            to = w->left;
            value = 0;
        }
    }
    bits.pop_back();
    int ret = query(to, bits, depth + 1) + ((1<<(29-depth))*value);
    return ret;
}

int main() {
    root = new Node;
    root->nodes = 0;
    root->left = NULL;
    root->right = NULL;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    
    int p;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p);
        vector<int> bits;
        for (int j = 0; j < 30; j++) {
            bits.push_back(p % 2);
            p /= 2;
        }
        insert(root, bits);
    }
        
    for (int i = 1; i <= n; i++) {
        vector<int> bits;
        int oldA = A[i];
        for (int j = 0; j < 30; j++) {
            bits.push_back(A[i] % 2);
            A[i] /= 2;
        }
        printf("%d ", oldA^query(root, bits, 0));
    }
        
    return 0;
}