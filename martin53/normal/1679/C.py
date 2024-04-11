import sys
def get_ints(): return list(map(int, sys.stdin.readline().strip().split()))

class fenwick_tree:

    def __init__(self,n):
        self.n=n;
        self.fenwick=[0 for _ in range(n+1)];

    def update(self,pos,val):
        while pos<=self.n:
            self.fenwick[pos]+=val;
            pos+=(pos&(-pos));

    def sum(self,pos):
        ret=0;

        while pos:
            ret+=self.fenwick[pos];
            pos-=(pos&(-pos));

        return ret;

    def query(self,l,r):
        if l>r:
            return 0;

        return self.sum(r)-self.sum(l-1);

class solver_1679C:

    def __init__(self):

        self.n,self.q=map(int,input().split(' '));

        self.x_active=fenwick_tree(self.n);
        self.x=fenwick_tree(self.n);

        self.y_active=fenwick_tree(self.n);
        self.y=fenwick_tree(self.n);

    def solve(self):
        for i in range(self.q):
            #arr=list(map(int,input().split(' ')));

            arr=get_ints();

            if arr[0]==1:
                x=arr[1];
                y=arr[2];

                self.x.update(x,1);
                self.y.update(y,1);

                if self.x.query(x,x)==1:
                    self.x_active.update(x,1);

                if self.y.query(y,y)==1:
                    self.y_active.update(y,1);

            elif arr[0] == 2:
                x = arr[1];
                y = arr[2];

                self.x.update(x, -1);
                self.y.update(y, -1);

                if self.x.query(x, x) == 0:
                    self.x_active.update(x, -1);

                if self.y.query(y, y) == 0:
                    self.y_active.update(y, -1);

            else:
                x1=arr[1];
                y1=arr[2];

                x2=arr[3];
                y2=arr[4];

                if self.x_active.query(x1,x2)==x2-x1+1 or self.y_active.query(y1,y2)==y2-y1+1:
                    print("Yes");
                else:
                    print("No");

cur=solver_1679C();

cur.solve();