program sol;
{
Problem A
Robot Bicorn Attack
start at 16:30 
}
var
    s:string[32];
    s1,s2,s3,i,j,ans:longint;
function tr(const s:string):longint;
var code:integer; tmp:longint;
begin
    if length(s)=0 then exit(-1);
    if length(s)>7 then exit(-1);
    if length(s)=1 then exit(ord(s[1])-48);
    if s[1]='0' then exit(-1);
    val(s,tmp,code);
    if tmp>1000000 then exit(-1);
    exit(tmp);
end;
begin
    readln(s); ans:=-1;
    for i:=1 to length(s) do begin
	s1:=tr(copy(s,1,i));
	if s1=-1 then continue;
	for j:=1 to length(s)-i do begin
	    s2:=tr(copy(s,i+1,j));
	    if s2=-1 then continue;
	    s3:=tr(copy(s,i+j+1,30));
	    if s3=-1 then continue;
	    if s1+s2+s3>ans then ans:=s1+s2+s3;
	end;
    end;
    writeln(ans);
end.