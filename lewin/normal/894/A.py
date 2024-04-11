s = raw_input()

q = 0
qa = 0
qaq = 0

for c in s:
    if c == 'Q':
        qaq += qa
        q += 1
    if c == 'A':
        qa += q
print qaq