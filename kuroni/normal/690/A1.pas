const
   fin='a110062016.inp';fon='a110062016.out';
var n:qword;
procedure solve;
begin
readln(n);
if n mod 2 = 0 then write(n div 2)
else write((n+1) div 2);
end;

begin
//assign(input,fin);reset(input);
//assign(output,fon);rewrite(output);
solve;
end.