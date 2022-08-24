import math
n = int(input())
symbs = ['a', 'b', 'c']
x = input()
y = input()
cur_ans = []
if x[0] != x[1] and y[0] != y[1]:
    for a in range(0, 3):
        for b in range(0, 3):
            if a == b:
                continue
            c = 3 - a - b
            u = str()
            u += symbs[a]
            u += symbs[b]
            u += symbs[c]
            ok = True
            for t in range(0, 2):
                if u[t] == x[0] and u[t + 1] == x[1]:
                    ok = False
                if u[t] == y[0] and u[t + 1] == y[1]:
                    ok = False
            if ok:
                for i in range(0, n):
                    cur_ans.append(symbs[a])
                for i in range(0, n):
                    cur_ans.append(symbs[b])
                for i in range(0, n):
                    cur_ans.append(symbs[c])
                print("YES")
                print("".join(x for x in cur_ans))
                exit(0)
for i in range(0, n):
    for a in range(0, 3):
        if len(cur_ans) > 3 * i:
            break
        for b in range(0, 3):
            if len(cur_ans) > 3 * i:
                break
            if a == b:
                continue
            c = 3 - a - b
            u = str()
            u += symbs[a]
            u += symbs[b]
            u += symbs[c]
            ok = True
            for t in range(0, 2):
                if u[t] == x[0] and u[t + 1] == x[1]:
                    ok = False
                if u[t] == y[0] and u[t + 1] == y[1]:
                    ok = False
                if i > 0 and cur_ans[-1] == x[0] and u[0] == x[1]:
                    ok = False
                if i > 0 and cur_ans[-1] == y[0] and u[0] == y[1]:
                    ok = False
            if ok:
                for c in u:
                    cur_ans.append(c)
                break
print("YES")
print("".join(x for x in cur_ans))