
class Solver1696C:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.a = list(map(int, input().split(' ')))
        self.k = int(input())
        self.b = list(map(int, input().split(' ')))

    def compress(self, arr):
        ret = []

        for i in range(len(arr)):
            cnt = 1

            while arr[i] % self.m == 0:
                cnt = cnt * self.m
                arr[i] = arr[i] // self.m

            if len(ret) and ret[len(ret)-1][0] == arr[i]:
                ret[len(ret)-1][1] += cnt
            else:
                ret.append([arr[i], cnt])

        return ret

    def solve(self):
        if self.compress(self.a) == self.compress(self.b):
            return "Yes"

        return "No"


t = int(input())

while t:

    t -= 1

    cur = Solver1696C()

    print(cur.solve())