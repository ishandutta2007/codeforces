var
s:string;
k,i:longint;
begin
read(s);
k:=length(s);
for i:=k downto 1 do
 s:=s+s[i];
 write(s);
end.