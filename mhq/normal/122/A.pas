program zhopa;
var
n : integer;
begin
readln(n);
if ((n mod 4 = 0) or (n mod 7 = 0) or (n mod 44 = 0) or (n mod 47 = 0) or (n mod 74 = 0) or (n mod 77 = 0) or (n mod 444 = 0) or (n mod 447 = 0) or (n mod 474 = 0) or (n mod 477 = 0) or (n mod 744 = 0) or (n mod 747 = 0) or (n mod 774 = 0) or (n mod 777 = 0)) then
writeln('YES')

else
writeln('NO');
end.