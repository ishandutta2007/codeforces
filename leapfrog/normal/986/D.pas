uses gmp;
var ch,_3:string;
	n,b,pw:MPInteger;
	ans,ln,temp:integer;
begin
	readln(ch);
	n:=ch;
	if ch='1' then
	begin
		writeln(1);
	end
	else
	begin
		b:=3;
		_3:=z_get_str(3,n); {3}
		{writeln(_3);}
		ln:=length(_3); {log_3n}
		pw:=z_pow_ui(b,ln-1);
		ans:=ln*3; {3log_3n}
		if pw>=n then ans:=(ln-1)*3
		else if pw*4>=n*3 then ans:=(ln-2)*3+4
		else if pw*2>=n then ans:=(ln-1)*3+2;
		writeln(ans);
	end;
end.