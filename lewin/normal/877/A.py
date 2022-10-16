s = raw_input()
b = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
g = sum(s.count(x) for x in b)
print (g == 1) * "YES" or "NO"