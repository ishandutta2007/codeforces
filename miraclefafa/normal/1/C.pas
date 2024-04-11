uses math;
const zero=1e-6;
type vector=record x,y:extended;end;
var
	p1,p2,p3:vector;
	la,lb,lc,a,b,c,R:extended;
	tmp,i:longint;
function get(a,b,c:extended):extended;
begin
	exit(arccos((b*b+c*c-a*a)/(2*b*c)));
end;
function dis(a,b:vector):extended;
begin
	exit(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
end;
function check(x:extended):boolean;
begin
	tmp:=round(x/pi);
	if abs(tmp*pi-x)/x<zero then exit(true) else exit(false);
end;
begin
	readln(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	la:=dis(p1,p2);lb:=dis(p1,p3);lc:=dis(p2,p3);
	a:=get(la,lb,lc);b:=get(lb,la,lc);c:=get(lc,la,lb);
	i:=3;R:=la/(sin(a)*2);
	while true do
	begin
		if check(a*i) and check(b*i) and check(c*i) then break;
		inc(i);
	end;
	writeln(sin(2*pi/i)*r*r*i/2:0:6);
end.