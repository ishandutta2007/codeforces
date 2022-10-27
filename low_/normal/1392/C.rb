# your code goes here

t = gets.chomp.to_i
for tc in 1..t
	n = gets.chomp.to_i;
	a = gets.split
	for i in 0..(n-1)
		a[i] = a[i].to_i
	end
	b = Array.new(n, 0)
	max = a[0]
	for i in 1..(n-1)
		if a[i] > max
			max = a[i]
		end
		b[i] = max - a[i]
	end
	ans = 0
	for i in 1..(n-1)
		if b[i] > b[i-1]
			ans += b[i] - b[i-1]
		end
	end
	puts ans
end