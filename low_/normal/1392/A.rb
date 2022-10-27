# your code goes here

# a = gets.chomp.to_i

# b = gets.chomp.to_i

# puts (a+b)
t = gets.chomp.to_i
for tc in 1..t
	n = gets.chomp.to_i
	a = gets.split
	b = false
	for i in 1..(n-1)
		if a[i] != a[i-1]
			b = true;
		end
	end
	if b
		puts 1
	else
		puts n
	end
end